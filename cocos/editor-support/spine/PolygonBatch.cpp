/******************************************************************************
 * Spine Runtimes Software License
 * Version 2.1
 * 
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 * 
 * You are granted a perpetual, non-exclusive, non-sublicensable and
 * non-transferable license to install, execute and perform the Spine Runtimes
 * Software (the "Software") solely for internal use. Without the written
 * permission of Esoteric Software (typically granted by licensing Spine), you
 * may not (a) modify, translate, adapt or otherwise create derivative works,
 * improvements of the Software or develop new applications using the Software
 * or (b) remove, delete, alter or obscure any trademarks or any copyright,
 * trademark, patent or other intellectual property or proprietary rights
 * notices on or in the Software, including any copy thereof. Redistributions
 * in binary or source form must include this license and terms.
 * 
 * THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ESOTERIC SOFTARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#include <spine/PolygonBatch.h>
#include <spine/extension.h>

USING_NS_CC;

namespace spine {

PolygonBatch* PolygonBatch::createWithCapacity (ssize_t capacity) {
	PolygonBatch* batch = new PolygonBatch();
	batch->initWithCapacity(capacity);
	batch->autorelease();
	return batch;
}

PolygonBatch::PolygonBatch () :
	_capacity(0),
	_texture(nullptr)
{}

bool PolygonBatch::initWithCapacity (ssize_t capacity) {
	// 32767 is max index, so 32767 / 3 - (32767 / 3 % 3) = 10920.
	CCASSERT(capacity <= 10920, "capacity cannot be > 10920");
	CCASSERT(capacity >= 0, "capacity cannot be < 0");
	_capacity = capacity;
	_vertices.reserve(capacity);
	_triangles.reserve(capacity * 3);
    
    _programState = new backend::ProgramState(positionTextureColor_vert, positionTextureColor_frag);
    auto &pipelineDescriptor = _customCommand.getPipelineDescriptor();

    auto &layout = pipelineDescriptor.vertexLayout;
    layout.setAtrribute("a_position", 0, backend::VertexFormat::FLOAT2, 0, false);
    layout.setAtrribute("a_texCoord", 1, backend::VertexFormat::FLOAT2, offsetof(V2F_C4B_T2F, texCoords), false);
    layout.setAtrribute("a_color", 2, backend::VertexFormat::UBYTE4, offsetof(V2F_C4B_T2F, colors), true);
    layout.setLayout(sizeof(V2F_C4B_T2F), backend::VertexStepMode::VERTEX);

    _locMVP = _programState->getUniformLocation("u_MVPMatrix");
    _locTexture = _programState->getUniformLocation("u_texture");

    pipelineDescriptor.programState = _programState;
	return true;
}

PolygonBatch::~PolygonBatch () {
    CC_SAFE_RELEASE_NULL(_programState);
}

void PolygonBatch::add (const cocos2d::Mat4 &mat, const Texture2D* addTexture,
		const float* addVertices, const float* uvs, int addVerticesCount,
		const int* addTriangles, int addTrianglesCount,
		Color4B* color) {

	if (
		addTexture != _texture
		|| _vertices.size() + (addVerticesCount >> 1) > _capacity
		|| _triangles.size() + addTrianglesCount > _capacity * 3) {
		this->flush(mat);
		_texture = addTexture;
	}
    const int triangleCount = _triangles.size();
    const int verticesCount = _vertices.size();
	for (int i = 0; i < addTrianglesCount; ++i)
		_triangles.push_back(addTriangles[i] + verticesCount);

	for (int i = 0; i < addVerticesCount; i += 2) {
        V2F_C4B_T2F vertex;
		vertex.vertices.x = addVertices[i];
		vertex.vertices.y = addVertices[i + 1];
		vertex.colors = *color;
		vertex.texCoords.u = uvs[i];
		vertex.texCoords.v = uvs[i + 1];
        _vertices.push_back(vertex);
	}
}

void PolygonBatch::flush(const cocos2d::Mat4 &mat) {
	if (!_vertices.size()) return;

    auto *renderer = Director::getInstance()->getRenderer();

    auto pMatrix = Director::getInstance()->getMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    auto fMatrix = pMatrix * mat;

    _programState->setUniform(_locMVP, &fMatrix.m, sizeof(fMatrix.m));
    _programState->setTexture(_locTexture, 0, _texture->getBackendTexture());

    _customCommand.createVertexBuffer(sizeof(V2F_C4B_T2F), _vertices.size(), CustomCommand::BufferUsage::DYNAMIC);
    _customCommand.createIndexBuffer(CustomCommand::IndexFormat::U_SHORT, _triangles.size(), CustomCommand::BufferUsage::DYNAMIC);

    _customCommand.updateIndexBuffer(_triangles.data(), sizeof(_triangles[0]) * _triangles.size());
    _customCommand.updateVertexBuffer(_vertices.data(), sizeof(_vertices[0]) * _vertices.size());

	CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, _vertices.size());

    _vertices.resize(0);
    _triangles.resize(0);
    renderer->addCommand(&_customCommand);

	CHECK_GL_ERROR_DEBUG();
}

void PolygonBatch::setBlend(cocos2d::backend::BlendFactor src, cocos2d::backend::BlendFactor dst)
{
    auto &desciptor = _customCommand.getPipelineDescriptor().blendDescriptor;
    desciptor.blendEnabled = true;
    desciptor.sourceAlphaBlendFactor = desciptor.sourceRGBBlendFactor = src;
    desciptor.destinationAlphaBlendFactor = desciptor.destinationRGBBlendFactor = dst;
}

}
