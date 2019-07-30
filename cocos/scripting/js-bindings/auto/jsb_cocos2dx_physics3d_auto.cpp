#include "scripting/js-bindings/auto/jsb_cocos2dx_physics3d_auto.hpp"
#if CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "physics3d/CCPhysics3D.h"
#include "scripting/js-bindings/manual/physics3d/jsb_cocos2dx_physics3d_manual.h"

se::Object* __jsb_cocos2d_Physics3DShape_proto = nullptr;
se::Class* __jsb_cocos2d_Physics3DShape_class = nullptr;

static bool js_cocos2dx_physics3d_Physics3DShape_initConvexHull(se::State& s)
{
    cocos2d::Physics3DShape* cobj = (cocos2d::Physics3DShape*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DShape_initConvexHull : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const cocos2d::Vec3* arg0 = nullptr;
        int arg1 = 0;
        ok &= seval_to_native_ptr(args[0], &arg0);
        do { int32_t tmp = 0; ok &= seval_to_int32(args[1], &tmp); arg1 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_initConvexHull : Error processing arguments");
        bool result = cobj->initConvexHull(arg0, arg1);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_initConvexHull : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DShape_initConvexHull)

static bool js_cocos2dx_physics3d_Physics3DShape_getbtShape(se::State& s)
{
    cocos2d::Physics3DShape* cobj = (cocos2d::Physics3DShape*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DShape_getbtShape : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        btCollisionShape* result = cobj->getbtShape();
        ok &= native_ptr_to_seval<btCollisionShape>((btCollisionShape*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_getbtShape : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DShape_getbtShape)

static bool js_cocos2dx_physics3d_Physics3DShape_initSphere(se::State& s)
{
    cocos2d::Physics3DShape* cobj = (cocos2d::Physics3DShape*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DShape_initSphere : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_initSphere : Error processing arguments");
        bool result = cobj->initSphere(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_initSphere : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DShape_initSphere)

static bool js_cocos2dx_physics3d_Physics3DShape_initBox(se::State& s)
{
    cocos2d::Physics3DShape* cobj = (cocos2d::Physics3DShape*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DShape_initBox : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_initBox : Error processing arguments");
        bool result = cobj->initBox(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_initBox : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DShape_initBox)

static bool js_cocos2dx_physics3d_Physics3DShape_initCapsule(se::State& s)
{
    cocos2d::Physics3DShape* cobj = (cocos2d::Physics3DShape*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DShape_initCapsule : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_initCapsule : Error processing arguments");
        bool result = cobj->initCapsule(arg0, arg1);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_initCapsule : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DShape_initCapsule)

static bool js_cocos2dx_physics3d_Physics3DShape_initCylinder(se::State& s)
{
    cocos2d::Physics3DShape* cobj = (cocos2d::Physics3DShape*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DShape_initCylinder : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_initCylinder : Error processing arguments");
        bool result = cobj->initCylinder(arg0, arg1);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_initCylinder : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DShape_initCylinder)

static bool js_cocos2dx_physics3d_Physics3DShape_getShapeType(se::State& s)
{
    cocos2d::Physics3DShape* cobj = (cocos2d::Physics3DShape*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DShape_getShapeType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = (int)cobj->getShapeType();
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_getShapeType : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DShape_getShapeType)

static bool js_cocos2dx_physics3d_Physics3DShape_createBox(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_createBox : Error processing arguments");
        auto result = cocos2d::Physics3DShape::createBox(arg0);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_Physics3DShape_class);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DShape_createBox)

static bool js_cocos2dx_physics3d_Physics3DShape_createCylinder(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_createCylinder : Error processing arguments");
        auto result = cocos2d::Physics3DShape::createCylinder(arg0, arg1);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_Physics3DShape_class);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DShape_createCylinder)

static bool js_cocos2dx_physics3d_Physics3DShape_createConvexHull(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        const cocos2d::Vec3* arg0 = nullptr;
        int arg1 = 0;
        ok &= seval_to_native_ptr(args[0], &arg0);
        do { int32_t tmp = 0; ok &= seval_to_int32(args[1], &tmp); arg1 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_createConvexHull : Error processing arguments");
        auto result = cocos2d::Physics3DShape::createConvexHull(arg0, arg1);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_Physics3DShape_class);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DShape_createConvexHull)

static bool js_cocos2dx_physics3d_Physics3DShape_createCapsule(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_createCapsule : Error processing arguments");
        auto result = cocos2d::Physics3DShape::createCapsule(arg0, arg1);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_Physics3DShape_class);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DShape_createCapsule)

static bool js_cocos2dx_physics3d_Physics3DShape_createSphere(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DShape_createSphere : Error processing arguments");
        auto result = cocos2d::Physics3DShape::createSphere(arg0);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_Physics3DShape_class);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DShape_createSphere)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Physics3DShape_finalize)

static bool js_cocos2dx_physics3d_Physics3DShape_constructor(se::State& s)
{
    cocos2d::Physics3DShape* cobj = new (std::nothrow) cocos2d::Physics3DShape();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_physics3d_Physics3DShape_constructor, __jsb_cocos2d_Physics3DShape_class, js_cocos2d_Physics3DShape_finalize)




static bool js_cocos2d_Physics3DShape_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::Physics3DShape)", s.nativeThisObject());
    cocos2d::Physics3DShape* cobj = (cocos2d::Physics3DShape*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Physics3DShape_finalize)

bool js_register_cocos2dx_physics3d_Physics3DShape(se::Object* obj)
{
    auto cls = se::Class::create("Physics3DShape", obj, nullptr, _SE(js_cocos2dx_physics3d_Physics3DShape_constructor));

    cls->defineFunction("initConvexHull", _SE(js_cocos2dx_physics3d_Physics3DShape_initConvexHull));
    cls->defineFunction("getbtShape", _SE(js_cocos2dx_physics3d_Physics3DShape_getbtShape));
    cls->defineFunction("initSphere", _SE(js_cocos2dx_physics3d_Physics3DShape_initSphere));
    cls->defineFunction("initBox", _SE(js_cocos2dx_physics3d_Physics3DShape_initBox));
    cls->defineFunction("initCapsule", _SE(js_cocos2dx_physics3d_Physics3DShape_initCapsule));
    cls->defineFunction("initCylinder", _SE(js_cocos2dx_physics3d_Physics3DShape_initCylinder));
    cls->defineFunction("getShapeType", _SE(js_cocos2dx_physics3d_Physics3DShape_getShapeType));
    cls->defineStaticFunction("createBox", _SE(js_cocos2dx_physics3d_Physics3DShape_createBox));
    cls->defineStaticFunction("createCylinder", _SE(js_cocos2dx_physics3d_Physics3DShape_createCylinder));
    cls->defineStaticFunction("createConvexHull", _SE(js_cocos2dx_physics3d_Physics3DShape_createConvexHull));
    cls->defineStaticFunction("createCapsule", _SE(js_cocos2dx_physics3d_Physics3DShape_createCapsule));
    cls->defineStaticFunction("createSphere", _SE(js_cocos2dx_physics3d_Physics3DShape_createSphere));
    cls->defineFinalizeFunction(_SE(js_cocos2d_Physics3DShape_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Physics3DShape>(cls);

    __jsb_cocos2d_Physics3DShape_proto = cls->getProto();
    __jsb_cocos2d_Physics3DShape_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_cocos2d_Physics3DObject_proto = nullptr;
se::Class* __jsb_cocos2d_Physics3DObject_class = nullptr;

static bool js_cocos2dx_physics3d_Physics3DObject_setUserData(se::State& s)
{
    cocos2d::Physics3DObject* cobj = (cocos2d::Physics3DObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DObject_setUserData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        void* arg0 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR void*
        ok = false;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DObject_setUserData : Error processing arguments");
        cobj->setUserData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DObject_setUserData)

static bool js_cocos2dx_physics3d_Physics3DObject_getUserData(se::State& s)
{
    cocos2d::Physics3DObject* cobj = (cocos2d::Physics3DObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DObject_getUserData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        void* result = cobj->getUserData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DObject_getUserData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DObject_getUserData)

static bool js_cocos2dx_physics3d_Physics3DObject_getObjType(se::State& s)
{
    cocos2d::Physics3DObject* cobj = (cocos2d::Physics3DObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DObject_getObjType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = (int)cobj->getObjType();
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DObject_getObjType : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DObject_getObjType)

static bool js_cocos2dx_physics3d_Physics3DObject_setPhysicsWorld(se::State& s)
{
    cocos2d::Physics3DObject* cobj = (cocos2d::Physics3DObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DObject_setPhysicsWorld : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Physics3DWorld* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DObject_setPhysicsWorld : Error processing arguments");
        cobj->setPhysicsWorld(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DObject_setPhysicsWorld)

static bool js_cocos2dx_physics3d_Physics3DObject_getWorldTransform(se::State& s)
{
    cocos2d::Physics3DObject* cobj = (cocos2d::Physics3DObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DObject_getWorldTransform : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Mat4 result = cobj->getWorldTransform();
        ok &= Mat4_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DObject_getWorldTransform : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DObject_getWorldTransform)

static bool js_cocos2dx_physics3d_Physics3DObject_getPhysicsWorld(se::State& s)
{
    cocos2d::Physics3DObject* cobj = (cocos2d::Physics3DObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DObject_getPhysicsWorld : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Physics3DWorld* result = cobj->getPhysicsWorld();
        ok &= native_ptr_to_seval<cocos2d::Physics3DWorld>((cocos2d::Physics3DWorld*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DObject_getPhysicsWorld : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DObject_getPhysicsWorld)

static bool js_cocos2dx_physics3d_Physics3DObject_setMask(se::State& s)
{
    cocos2d::Physics3DObject* cobj = (cocos2d::Physics3DObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DObject_setMask : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DObject_setMask : Error processing arguments");
        cobj->setMask(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DObject_setMask)

static bool js_cocos2dx_physics3d_Physics3DObject_getCollisionCallback(se::State& s)
{
    cocos2d::Physics3DObject* cobj = (cocos2d::Physics3DObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DObject_getCollisionCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::function<void (const cocos2d::Physics3DCollisionInfo &)>& result = cobj->getCollisionCallback();
        #pragma warning NO CONVERSION FROM NATIVE FOR std::function;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DObject_getCollisionCallback : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DObject_getCollisionCallback)

static bool js_cocos2dx_physics3d_Physics3DObject_getMask(se::State& s)
{
    cocos2d::Physics3DObject* cobj = (cocos2d::Physics3DObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DObject_getMask : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = cobj->getMask();
        ok &= uint32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DObject_getMask : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DObject_getMask)

static bool js_cocos2dx_physics3d_Physics3DObject_needCollisionCallback(se::State& s)
{
    cocos2d::Physics3DObject* cobj = (cocos2d::Physics3DObject*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DObject_needCollisionCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->needCollisionCallback();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DObject_needCollisionCallback : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DObject_needCollisionCallback)




bool js_register_cocos2dx_physics3d_Physics3DObject(se::Object* obj)
{
    auto cls = se::Class::create("Physics3DObject", obj, nullptr, nullptr);

    cls->defineFunction("setUserData", _SE(js_cocos2dx_physics3d_Physics3DObject_setUserData));
    cls->defineFunction("getUserData", _SE(js_cocos2dx_physics3d_Physics3DObject_getUserData));
    cls->defineFunction("getObjType", _SE(js_cocos2dx_physics3d_Physics3DObject_getObjType));
    cls->defineFunction("setPhysicsWorld", _SE(js_cocos2dx_physics3d_Physics3DObject_setPhysicsWorld));
    cls->defineFunction("getWorldTransform", _SE(js_cocos2dx_physics3d_Physics3DObject_getWorldTransform));
    cls->defineFunction("getPhysicsWorld", _SE(js_cocos2dx_physics3d_Physics3DObject_getPhysicsWorld));
    cls->defineFunction("setMask", _SE(js_cocos2dx_physics3d_Physics3DObject_setMask));
    cls->defineFunction("getCollisionCallback", _SE(js_cocos2dx_physics3d_Physics3DObject_getCollisionCallback));
    cls->defineFunction("getMask", _SE(js_cocos2dx_physics3d_Physics3DObject_getMask));
    cls->defineFunction("needCollisionCallback", _SE(js_cocos2dx_physics3d_Physics3DObject_needCollisionCallback));
    cls->install();
    JSBClassType::registerClass<cocos2d::Physics3DObject>(cls);

    __jsb_cocos2d_Physics3DObject_proto = cls->getProto();
    __jsb_cocos2d_Physics3DObject_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_cocos2d_Physics3DRigidBody_proto = nullptr;
se::Class* __jsb_cocos2d_Physics3DRigidBody_class = nullptr;

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setGravity(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setGravity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setGravity : Error processing arguments");
        cobj->setGravity(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setGravity)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getFriction(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getFriction : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getFriction();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getFriction : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getFriction)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setAngularFactor(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setAngularFactor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            float arg0 = 0;
            ok &= seval_to_float(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cobj->setAngularFactor(arg0);
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            cocos2d::Vec3 arg0;
            ok &= seval_to_Vec3(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cobj->setAngularFactor(arg0);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setAngularFactor)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_addConstraint(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_addConstraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Physics3DConstraint* arg0 = 0;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_addConstraint : Error processing arguments");
        cobj->addConstraint(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_addConstraint)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getRigidBody(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getRigidBody : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        btRigidBody* result = cobj->getRigidBody();
        ok &= native_ptr_to_seval<btRigidBody>((btRigidBody*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getRigidBody : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getRigidBody)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getTotalForce(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getTotalForce : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getTotalForce();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getTotalForce : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getTotalForce)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getConstraintCount(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getConstraintCount : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = cobj->getConstraintCount();
        ok &= uint32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getConstraintCount : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getConstraintCount)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_applyCentralForce(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_applyCentralForce : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_applyCentralForce : Error processing arguments");
        cobj->applyCentralForce(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_applyCentralForce)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setMassProps(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setMassProps : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        cocos2d::Vec3 arg1;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_Vec3(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setMassProps : Error processing arguments");
        cobj->setMassProps(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setMassProps)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setFriction(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setFriction : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setFriction : Error processing arguments");
        cobj->setFriction(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setFriction)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setKinematic(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setKinematic : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setKinematic : Error processing arguments");
        cobj->setKinematic(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setKinematic)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setDamping(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setDamping : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setDamping : Error processing arguments");
        cobj->setDamping(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setDamping)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_applyImpulse(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_applyImpulse : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocos2d::Vec3 arg0;
        cocos2d::Vec3 arg1;
        ok &= seval_to_Vec3(args[0], &arg0);
        ok &= seval_to_Vec3(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_applyImpulse : Error processing arguments");
        cobj->applyImpulse(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_applyImpulse)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_isKinematic(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_isKinematic : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isKinematic();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_isKinematic : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_isKinematic)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_applyTorque(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_applyTorque : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_applyTorque : Error processing arguments");
        cobj->applyTorque(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_applyTorque)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setCcdMotionThreshold(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setCcdMotionThreshold : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setCcdMotionThreshold : Error processing arguments");
        cobj->setCcdMotionThreshold(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setCcdMotionThreshold)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setRollingFriction(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setRollingFriction : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setRollingFriction : Error processing arguments");
        cobj->setRollingFriction(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setRollingFriction)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getCcdMotionThreshold(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getCcdMotionThreshold : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getCcdMotionThreshold();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getCcdMotionThreshold : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getCcdMotionThreshold)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getLinearFactor(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getLinearFactor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getLinearFactor();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getLinearFactor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getLinearFactor)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_applyDamping(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_applyDamping : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_applyDamping : Error processing arguments");
        cobj->applyDamping(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_applyDamping)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getAngularVelocity(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getAngularVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getAngularVelocity();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getAngularVelocity : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getAngularVelocity)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_init(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Physics3DRigidBodyDes* arg0 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR Physics3DRigidBodyDes*
        ok = false;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_init : Error processing arguments");
        bool result = cobj->init(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_init)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_applyTorqueImpulse(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_applyTorqueImpulse : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_applyTorqueImpulse : Error processing arguments");
        cobj->applyTorqueImpulse(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_applyTorqueImpulse)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setActive(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setActive : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setActive : Error processing arguments");
        cobj->setActive(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setActive)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setLinearFactor(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setLinearFactor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setLinearFactor : Error processing arguments");
        cobj->setLinearFactor(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setLinearFactor)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setLinearVelocity(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setLinearVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setLinearVelocity : Error processing arguments");
        cobj->setLinearVelocity(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setLinearVelocity)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getLinearVelocity(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getLinearVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getLinearVelocity();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getLinearVelocity : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getLinearVelocity)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setCcdSweptSphereRadius(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setCcdSweptSphereRadius : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setCcdSweptSphereRadius : Error processing arguments");
        cobj->setCcdSweptSphereRadius(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setCcdSweptSphereRadius)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_applyForce(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_applyForce : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocos2d::Vec3 arg0;
        cocos2d::Vec3 arg1;
        ok &= seval_to_Vec3(args[0], &arg0);
        ok &= seval_to_Vec3(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_applyForce : Error processing arguments");
        cobj->applyForce(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_applyForce)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setAngularVelocity(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setAngularVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setAngularVelocity : Error processing arguments");
        cobj->setAngularVelocity(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setAngularVelocity)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_applyCentralImpulse(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_applyCentralImpulse : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_applyCentralImpulse : Error processing arguments");
        cobj->applyCentralImpulse(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_applyCentralImpulse)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getGravity(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getGravity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getGravity();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getGravity : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getGravity)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getRollingFriction(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getRollingFriction : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRollingFriction();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getRollingFriction : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getRollingFriction)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setCenterOfMassTransform(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setCenterOfMassTransform : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Mat4 arg0;
        ok &= seval_to_Mat4(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setCenterOfMassTransform : Error processing arguments");
        cobj->setCenterOfMassTransform(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setCenterOfMassTransform)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setInvInertiaDiagLocal(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setInvInertiaDiagLocal : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setInvInertiaDiagLocal : Error processing arguments");
        cobj->setInvInertiaDiagLocal(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setInvInertiaDiagLocal)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_removeConstraint(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_removeConstraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            unsigned int arg0 = 0;
            ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
            if (!ok) { ok = true; break; }
            cobj->removeConstraint(arg0);
            return true;
        }
    } while(false);

    do {
        if (argc == 1) {
            cocos2d::Physics3DConstraint* arg0 = 0;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cobj->removeConstraint(arg0);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_removeConstraint)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getTotalTorque(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getTotalTorque : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getTotalTorque();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getTotalTorque : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getTotalTorque)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getInvMass(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getInvMass : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getInvMass();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getInvMass : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getInvMass)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getConstraint(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getConstraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getConstraint : Error processing arguments");
        cocos2d::Physics3DConstraint* result = cobj->getConstraint(arg0);
        ok &= native_ptr_to_seval<cocos2d::Physics3DConstraint>((cocos2d::Physics3DConstraint*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getConstraint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getConstraint)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getRestitution(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getRestitution : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRestitution();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getRestitution : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getRestitution)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getCcdSweptSphereRadius(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getCcdSweptSphereRadius : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getCcdSweptSphereRadius();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getCcdSweptSphereRadius : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getCcdSweptSphereRadius)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getHitFraction(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getHitFraction : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getHitFraction();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getHitFraction : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getHitFraction)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getAngularDamping(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getAngularDamping : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAngularDamping();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getAngularDamping : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getAngularDamping)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getInvInertiaDiagLocal(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getInvInertiaDiagLocal : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getInvInertiaDiagLocal();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getInvInertiaDiagLocal : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getInvInertiaDiagLocal)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getCenterOfMassTransform(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getCenterOfMassTransform : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Mat4 result = cobj->getCenterOfMassTransform();
        ok &= Mat4_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getCenterOfMassTransform : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getCenterOfMassTransform)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getAngularFactor(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getAngularFactor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getAngularFactor();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getAngularFactor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getAngularFactor)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setRestitution(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setRestitution : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setRestitution : Error processing arguments");
        cobj->setRestitution(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setRestitution)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_setHitFraction(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setHitFraction : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_setHitFraction : Error processing arguments");
        cobj->setHitFraction(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_setHitFraction)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_getLinearDamping(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getLinearDamping : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getLinearDamping();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DRigidBody_getLinearDamping : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DRigidBody_getLinearDamping)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Physics3DRigidBody_finalize)

static bool js_cocos2dx_physics3d_Physics3DRigidBody_constructor(se::State& s)
{
    cocos2d::Physics3DRigidBody* cobj = new (std::nothrow) cocos2d::Physics3DRigidBody();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_physics3d_Physics3DRigidBody_constructor, __jsb_cocos2d_Physics3DRigidBody_class, js_cocos2d_Physics3DRigidBody_finalize)



extern se::Object* __jsb_cocos2d_Physics3DObject_proto;

static bool js_cocos2d_Physics3DRigidBody_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::Physics3DRigidBody)", s.nativeThisObject());
    cocos2d::Physics3DRigidBody* cobj = (cocos2d::Physics3DRigidBody*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Physics3DRigidBody_finalize)

bool js_register_cocos2dx_physics3d_Physics3DRigidBody(se::Object* obj)
{
    auto cls = se::Class::create("Physics3DRigidBody", obj, __jsb_cocos2d_Physics3DObject_proto, _SE(js_cocos2dx_physics3d_Physics3DRigidBody_constructor));

    cls->defineFunction("setGravity", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setGravity));
    cls->defineFunction("getFriction", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getFriction));
    cls->defineFunction("setAngularFactor", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setAngularFactor));
    cls->defineFunction("addConstraint", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_addConstraint));
    cls->defineFunction("getRigidBody", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getRigidBody));
    cls->defineFunction("getTotalForce", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getTotalForce));
    cls->defineFunction("getConstraintCount", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getConstraintCount));
    cls->defineFunction("applyCentralForce", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_applyCentralForce));
    cls->defineFunction("setMassProps", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setMassProps));
    cls->defineFunction("setFriction", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setFriction));
    cls->defineFunction("setKinematic", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setKinematic));
    cls->defineFunction("setDamping", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setDamping));
    cls->defineFunction("applyImpulse", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_applyImpulse));
    cls->defineFunction("isKinematic", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_isKinematic));
    cls->defineFunction("applyTorque", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_applyTorque));
    cls->defineFunction("setCcdMotionThreshold", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setCcdMotionThreshold));
    cls->defineFunction("setRollingFriction", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setRollingFriction));
    cls->defineFunction("getCcdMotionThreshold", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getCcdMotionThreshold));
    cls->defineFunction("getLinearFactor", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getLinearFactor));
    cls->defineFunction("applyDamping", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_applyDamping));
    cls->defineFunction("getAngularVelocity", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getAngularVelocity));
    cls->defineFunction("init", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_init));
    cls->defineFunction("applyTorqueImpulse", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_applyTorqueImpulse));
    cls->defineFunction("setActive", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setActive));
    cls->defineFunction("setLinearFactor", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setLinearFactor));
    cls->defineFunction("setLinearVelocity", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setLinearVelocity));
    cls->defineFunction("getLinearVelocity", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getLinearVelocity));
    cls->defineFunction("setCcdSweptSphereRadius", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setCcdSweptSphereRadius));
    cls->defineFunction("applyForce", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_applyForce));
    cls->defineFunction("setAngularVelocity", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setAngularVelocity));
    cls->defineFunction("applyCentralImpulse", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_applyCentralImpulse));
    cls->defineFunction("getGravity", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getGravity));
    cls->defineFunction("getRollingFriction", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getRollingFriction));
    cls->defineFunction("setCenterOfMassTransform", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setCenterOfMassTransform));
    cls->defineFunction("setInvInertiaDiagLocal", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setInvInertiaDiagLocal));
    cls->defineFunction("removeConstraint", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_removeConstraint));
    cls->defineFunction("getTotalTorque", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getTotalTorque));
    cls->defineFunction("getInvMass", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getInvMass));
    cls->defineFunction("getConstraint", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getConstraint));
    cls->defineFunction("getRestitution", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getRestitution));
    cls->defineFunction("getCcdSweptSphereRadius", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getCcdSweptSphereRadius));
    cls->defineFunction("getHitFraction", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getHitFraction));
    cls->defineFunction("getAngularDamping", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getAngularDamping));
    cls->defineFunction("getInvInertiaDiagLocal", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getInvInertiaDiagLocal));
    cls->defineFunction("getCenterOfMassTransform", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getCenterOfMassTransform));
    cls->defineFunction("getAngularFactor", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getAngularFactor));
    cls->defineFunction("setRestitution", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setRestitution));
    cls->defineFunction("setHitFraction", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_setHitFraction));
    cls->defineFunction("getLinearDamping", _SE(js_cocos2dx_physics3d_Physics3DRigidBody_getLinearDamping));
    cls->defineFinalizeFunction(_SE(js_cocos2d_Physics3DRigidBody_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Physics3DRigidBody>(cls);

    __jsb_cocos2d_Physics3DRigidBody_proto = cls->getProto();
    __jsb_cocos2d_Physics3DRigidBody_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_cocos2d_Physics3DComponent_proto = nullptr;
se::Class* __jsb_cocos2d_Physics3DComponent_class = nullptr;

static bool js_cocos2dx_physics3d_Physics3DComponent_syncNodeToPhysics(se::State& s)
{
    cocos2d::Physics3DComponent* cobj = (cocos2d::Physics3DComponent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DComponent_syncNodeToPhysics : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->syncNodeToPhysics();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DComponent_syncNodeToPhysics)

static bool js_cocos2dx_physics3d_Physics3DComponent_addToPhysicsWorld(se::State& s)
{
    cocos2d::Physics3DComponent* cobj = (cocos2d::Physics3DComponent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DComponent_addToPhysicsWorld : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Physics3DWorld* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DComponent_addToPhysicsWorld : Error processing arguments");
        cobj->addToPhysicsWorld(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DComponent_addToPhysicsWorld)

static bool js_cocos2dx_physics3d_Physics3DComponent_syncPhysicsToNode(se::State& s)
{
    cocos2d::Physics3DComponent* cobj = (cocos2d::Physics3DComponent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DComponent_syncPhysicsToNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->syncPhysicsToNode();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DComponent_syncPhysicsToNode)

static bool js_cocos2dx_physics3d_Physics3DComponent_getPhysics3DObject(se::State& s)
{
    cocos2d::Physics3DComponent* cobj = (cocos2d::Physics3DComponent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DComponent_getPhysics3DObject : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Physics3DObject* result = cobj->getPhysics3DObject();
        ok &= native_ptr_to_seval<cocos2d::Physics3DObject>((cocos2d::Physics3DObject*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DComponent_getPhysics3DObject : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DComponent_getPhysics3DObject)

static bool js_cocos2dx_physics3d_Physics3DComponent_setPhysics3DObject(se::State& s)
{
    cocos2d::Physics3DComponent* cobj = (cocos2d::Physics3DComponent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DComponent_setPhysics3DObject : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Physics3DObject* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DComponent_setPhysics3DObject : Error processing arguments");
        cobj->setPhysics3DObject(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DComponent_setPhysics3DObject)

static bool js_cocos2dx_physics3d_Physics3DComponent_setSyncFlag(se::State& s)
{
    cocos2d::Physics3DComponent* cobj = (cocos2d::Physics3DComponent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DComponent_setSyncFlag : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Physics3DComponent::PhysicsSyncFlag arg0;
        do { int32_t tmp = 0; ok &= seval_to_int32(args[0], &tmp); arg0 = (cocos2d::Physics3DComponent::PhysicsSyncFlag)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DComponent_setSyncFlag : Error processing arguments");
        cobj->setSyncFlag(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DComponent_setSyncFlag)

static bool js_cocos2dx_physics3d_Physics3DComponent_setTransformInPhysics(se::State& s)
{
    cocos2d::Physics3DComponent* cobj = (cocos2d::Physics3DComponent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DComponent_setTransformInPhysics : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocos2d::Vec3 arg0;
        cocos2d::Quaternion arg1;
        ok &= seval_to_Vec3(args[0], &arg0);
        ok &= seval_to_Quaternion(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DComponent_setTransformInPhysics : Error processing arguments");
        cobj->setTransformInPhysics(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DComponent_setTransformInPhysics)

static bool js_cocos2dx_physics3d_Physics3DComponent_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 1) {
            cocos2d::Physics3DObject* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DComponent* result = cocos2d::Physics3DComponent::create(arg0);
            ok &= native_ptr_to_seval<cocos2d::Physics3DComponent>((cocos2d::Physics3DComponent*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DComponent_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 2) {
            cocos2d::Physics3DObject* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg1;
            ok &= seval_to_Vec3(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DComponent* result = cocos2d::Physics3DComponent::create(arg0, arg1);
            ok &= native_ptr_to_seval<cocos2d::Physics3DComponent>((cocos2d::Physics3DComponent*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DComponent_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 3) {
            cocos2d::Physics3DObject* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg1;
            ok &= seval_to_Vec3(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Quaternion arg2;
            ok &= seval_to_Quaternion(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DComponent* result = cocos2d::Physics3DComponent::create(arg0, arg1, arg2);
            ok &= native_ptr_to_seval<cocos2d::Physics3DComponent>((cocos2d::Physics3DComponent*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DComponent_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 0) {
            cocos2d::Physics3DComponent* result = cocos2d::Physics3DComponent::create();
            ok &= native_ptr_to_seval<cocos2d::Physics3DComponent>((cocos2d::Physics3DComponent*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DComponent_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DComponent_create)

static bool js_cocos2dx_physics3d_Physics3DComponent_getPhysics3DComponentName(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        std::string& result = cocos2d::Physics3DComponent::getPhysics3DComponentName();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DComponent_getPhysics3DComponentName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DComponent_getPhysics3DComponentName)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Physics3DComponent_finalize)

static bool js_cocos2dx_physics3d_Physics3DComponent_constructor(se::State& s)
{
    cocos2d::Physics3DComponent* cobj = new (std::nothrow) cocos2d::Physics3DComponent();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_physics3d_Physics3DComponent_constructor, __jsb_cocos2d_Physics3DComponent_class, js_cocos2d_Physics3DComponent_finalize)



extern se::Object* __jsb_cocos2d_Component_proto;

static bool js_cocos2d_Physics3DComponent_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::Physics3DComponent)", s.nativeThisObject());
    cocos2d::Physics3DComponent* cobj = (cocos2d::Physics3DComponent*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Physics3DComponent_finalize)

bool js_register_cocos2dx_physics3d_Physics3DComponent(se::Object* obj)
{
    auto cls = se::Class::create("Physics3DComponent", obj, __jsb_cocos2d_Component_proto, _SE(js_cocos2dx_physics3d_Physics3DComponent_constructor));

    cls->defineFunction("syncNodeToPhysics", _SE(js_cocos2dx_physics3d_Physics3DComponent_syncNodeToPhysics));
    cls->defineFunction("addToPhysicsWorld", _SE(js_cocos2dx_physics3d_Physics3DComponent_addToPhysicsWorld));
    cls->defineFunction("syncPhysicsToNode", _SE(js_cocos2dx_physics3d_Physics3DComponent_syncPhysicsToNode));
    cls->defineFunction("getPhysics3DObject", _SE(js_cocos2dx_physics3d_Physics3DComponent_getPhysics3DObject));
    cls->defineFunction("setPhysics3DObject", _SE(js_cocos2dx_physics3d_Physics3DComponent_setPhysics3DObject));
    cls->defineFunction("setSyncFlag", _SE(js_cocos2dx_physics3d_Physics3DComponent_setSyncFlag));
    cls->defineFunction("setTransformInPhysics", _SE(js_cocos2dx_physics3d_Physics3DComponent_setTransformInPhysics));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_physics3d_Physics3DComponent_create));
    cls->defineStaticFunction("getPhysics3DComponentName", _SE(js_cocos2dx_physics3d_Physics3DComponent_getPhysics3DComponentName));
    cls->defineFinalizeFunction(_SE(js_cocos2d_Physics3DComponent_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Physics3DComponent>(cls);

    __jsb_cocos2d_Physics3DComponent_proto = cls->getProto();
    __jsb_cocos2d_Physics3DComponent_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_cocos2d_PhysicsSprite3D_proto = nullptr;
se::Class* __jsb_cocos2d_PhysicsSprite3D_class = nullptr;

static bool js_cocos2dx_physics3d_PhysicsSprite3D_syncNodeToPhysics(se::State& s)
{
    cocos2d::PhysicsSprite3D* cobj = (cocos2d::PhysicsSprite3D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_PhysicsSprite3D_syncNodeToPhysics : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->syncNodeToPhysics();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_PhysicsSprite3D_syncNodeToPhysics)

static bool js_cocos2dx_physics3d_PhysicsSprite3D_syncPhysicsToNode(se::State& s)
{
    cocos2d::PhysicsSprite3D* cobj = (cocos2d::PhysicsSprite3D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_PhysicsSprite3D_syncPhysicsToNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->syncPhysicsToNode();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_PhysicsSprite3D_syncPhysicsToNode)

static bool js_cocos2dx_physics3d_PhysicsSprite3D_getPhysicsObj(se::State& s)
{
    cocos2d::PhysicsSprite3D* cobj = (cocos2d::PhysicsSprite3D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_PhysicsSprite3D_getPhysicsObj : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Physics3DObject* result = cobj->getPhysicsObj();
        ok &= native_ptr_to_seval<cocos2d::Physics3DObject>((cocos2d::Physics3DObject*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_PhysicsSprite3D_getPhysicsObj : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_PhysicsSprite3D_getPhysicsObj)

static bool js_cocos2dx_physics3d_PhysicsSprite3D_setSyncFlag(se::State& s)
{
    cocos2d::PhysicsSprite3D* cobj = (cocos2d::PhysicsSprite3D*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_PhysicsSprite3D_setSyncFlag : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Physics3DComponent::PhysicsSyncFlag arg0;
        do { int32_t tmp = 0; ok &= seval_to_int32(args[0], &tmp); arg0 = (cocos2d::Physics3DComponent::PhysicsSyncFlag)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_PhysicsSprite3D_setSyncFlag : Error processing arguments");
        cobj->setSyncFlag(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_PhysicsSprite3D_setSyncFlag)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_PhysicsSprite3D_finalize)

static bool js_cocos2dx_physics3d_PhysicsSprite3D_constructor(se::State& s)
{
    cocos2d::PhysicsSprite3D* cobj = new (std::nothrow) cocos2d::PhysicsSprite3D();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_physics3d_PhysicsSprite3D_constructor, __jsb_cocos2d_PhysicsSprite3D_class, js_cocos2d_PhysicsSprite3D_finalize)



extern se::Object* __jsb_cocos2d_Sprite3D_proto;

static bool js_cocos2d_PhysicsSprite3D_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::PhysicsSprite3D)", s.nativeThisObject());
    cocos2d::PhysicsSprite3D* cobj = (cocos2d::PhysicsSprite3D*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_PhysicsSprite3D_finalize)

bool js_register_cocos2dx_physics3d_PhysicsSprite3D(se::Object* obj)
{
    auto cls = se::Class::create("PhysicsSprite3D", obj, __jsb_cocos2d_Sprite3D_proto, _SE(js_cocos2dx_physics3d_PhysicsSprite3D_constructor));

    cls->defineFunction("syncNodeToPhysics", _SE(js_cocos2dx_physics3d_PhysicsSprite3D_syncNodeToPhysics));
    cls->defineFunction("syncPhysicsToNode", _SE(js_cocos2dx_physics3d_PhysicsSprite3D_syncPhysicsToNode));
    cls->defineFunction("getPhysicsObj", _SE(js_cocos2dx_physics3d_PhysicsSprite3D_getPhysicsObj));
    cls->defineFunction("setSyncFlag", _SE(js_cocos2dx_physics3d_PhysicsSprite3D_setSyncFlag));
    cls->defineFinalizeFunction(_SE(js_cocos2d_PhysicsSprite3D_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::PhysicsSprite3D>(cls);

    __jsb_cocos2d_PhysicsSprite3D_proto = cls->getProto();
    __jsb_cocos2d_PhysicsSprite3D_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_cocos2d_Physics3DWorld_proto = nullptr;
se::Class* __jsb_cocos2d_Physics3DWorld_class = nullptr;

static bool js_cocos2dx_physics3d_Physics3DWorld_setGravity(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_setGravity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_setGravity : Error processing arguments");
        cobj->setGravity(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_setGravity)

static bool js_cocos2dx_physics3d_Physics3DWorld_stepSimulate(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_stepSimulate : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_stepSimulate : Error processing arguments");
        cobj->stepSimulate(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_stepSimulate)

static bool js_cocos2dx_physics3d_Physics3DWorld_needCollisionChecking(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_needCollisionChecking : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->needCollisionChecking();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_needCollisionChecking : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_needCollisionChecking)

static bool js_cocos2dx_physics3d_Physics3DWorld_collisionChecking(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_collisionChecking : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->collisionChecking();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_collisionChecking)

static bool js_cocos2dx_physics3d_Physics3DWorld_setGhostPairCallback(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_setGhostPairCallback : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->setGhostPairCallback();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_setGhostPairCallback)

static bool js_cocos2dx_physics3d_Physics3DWorld_init(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Physics3DWorldDes* arg0 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR Physics3DWorldDes*
        ok = false;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_init : Error processing arguments");
        bool result = cobj->init(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_init : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_init)

static bool js_cocos2dx_physics3d_Physics3DWorld_removeAllPhysics3DObjects(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_removeAllPhysics3DObjects : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->removeAllPhysics3DObjects();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_removeAllPhysics3DObjects)

static bool js_cocos2dx_physics3d_Physics3DWorld_isDebugDrawEnabled(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_isDebugDrawEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isDebugDrawEnabled();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_isDebugDrawEnabled : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_isDebugDrawEnabled)

static bool js_cocos2dx_physics3d_Physics3DWorld_removeAllPhysics3DConstraints(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_removeAllPhysics3DConstraints : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->removeAllPhysics3DConstraints();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_removeAllPhysics3DConstraints)

static bool js_cocos2dx_physics3d_Physics3DWorld_getGravity(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_getGravity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getGravity();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_getGravity : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_getGravity)

static bool js_cocos2dx_physics3d_Physics3DWorld_removePhysics3DConstraint(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_removePhysics3DConstraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Physics3DConstraint* arg0 = 0;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_removePhysics3DConstraint : Error processing arguments");
        cobj->removePhysics3DConstraint(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_removePhysics3DConstraint)

static bool js_cocos2dx_physics3d_Physics3DWorld_addPhysics3DObject(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_addPhysics3DObject : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Physics3DObject* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_addPhysics3DObject : Error processing arguments");
        cobj->addPhysics3DObject(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_addPhysics3DObject)

static bool js_cocos2dx_physics3d_Physics3DWorld_setDebugDrawEnable(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_setDebugDrawEnable : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_setDebugDrawEnable : Error processing arguments");
        cobj->setDebugDrawEnable(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_setDebugDrawEnable)

static bool js_cocos2dx_physics3d_Physics3DWorld_removePhysics3DObject(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_removePhysics3DObject : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Physics3DObject* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_removePhysics3DObject : Error processing arguments");
        cobj->removePhysics3DObject(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_removePhysics3DObject)

static bool js_cocos2dx_physics3d_Physics3DWorld_getPhysicsObject(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_getPhysicsObject : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        const btCollisionObject* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_getPhysicsObject : Error processing arguments");
        cocos2d::Physics3DObject* result = cobj->getPhysicsObject(arg0);
        ok &= native_ptr_to_seval<cocos2d::Physics3DObject>((cocos2d::Physics3DObject*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_getPhysicsObject : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_getPhysicsObject)

static bool js_cocos2dx_physics3d_Physics3DWorld_addPhysics3DConstraint(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_addPhysics3DConstraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Physics3DConstraint* arg0 = 0;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_addPhysics3DConstraint : Error processing arguments");
        cobj->addPhysics3DConstraint(arg0);
        return true;
    }
    if (argc == 2) {
        cocos2d::Physics3DConstraint* arg0 = 0;
        bool arg1;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_boolean(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_addPhysics3DConstraint : Error processing arguments");
        cobj->addPhysics3DConstraint(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_addPhysics3DConstraint)

static bool js_cocos2dx_physics3d_Physics3DWorld_debugDraw(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_debugDraw : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Renderer* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_debugDraw : Error processing arguments");
        cobj->debugDraw(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_debugDraw)

static bool js_cocos2dx_physics3d_Physics3DWorld_sweepShape(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DWorld_sweepShape : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 4) {
        cocos2d::Physics3DShape* arg0 = nullptr;
        cocos2d::Mat4 arg1;
        cocos2d::Mat4 arg2;
        cocos2d::Physics3DWorld::HitResult* arg3 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_Mat4(args[1], &arg1);
        ok &= seval_to_Mat4(args[2], &arg2);
        #pragma warning NO CONVERSION TO NATIVE FOR HitResult*
        ok = false;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_sweepShape : Error processing arguments");
        bool result = cobj->sweepShape(arg0, arg1, arg2, arg3);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_sweepShape : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 4);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_sweepShape)

static bool js_cocos2dx_physics3d_Physics3DWorld_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Physics3DWorldDes* arg0 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR Physics3DWorldDes*
        ok = false;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DWorld_create : Error processing arguments");
        auto result = cocos2d::Physics3DWorld::create(arg0);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_Physics3DWorld_class);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DWorld_create)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Physics3DWorld_finalize)

static bool js_cocos2dx_physics3d_Physics3DWorld_constructor(se::State& s)
{
    cocos2d::Physics3DWorld* cobj = new (std::nothrow) cocos2d::Physics3DWorld();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_physics3d_Physics3DWorld_constructor, __jsb_cocos2d_Physics3DWorld_class, js_cocos2d_Physics3DWorld_finalize)




static bool js_cocos2d_Physics3DWorld_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::Physics3DWorld)", s.nativeThisObject());
    cocos2d::Physics3DWorld* cobj = (cocos2d::Physics3DWorld*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Physics3DWorld_finalize)

bool js_register_cocos2dx_physics3d_Physics3DWorld(se::Object* obj)
{
    auto cls = se::Class::create("Physics3DWorld", obj, nullptr, _SE(js_cocos2dx_physics3d_Physics3DWorld_constructor));

    cls->defineFunction("setGravity", _SE(js_cocos2dx_physics3d_Physics3DWorld_setGravity));
    cls->defineFunction("stepSimulate", _SE(js_cocos2dx_physics3d_Physics3DWorld_stepSimulate));
    cls->defineFunction("needCollisionChecking", _SE(js_cocos2dx_physics3d_Physics3DWorld_needCollisionChecking));
    cls->defineFunction("collisionChecking", _SE(js_cocos2dx_physics3d_Physics3DWorld_collisionChecking));
    cls->defineFunction("setGhostPairCallback", _SE(js_cocos2dx_physics3d_Physics3DWorld_setGhostPairCallback));
    cls->defineFunction("init", _SE(js_cocos2dx_physics3d_Physics3DWorld_init));
    cls->defineFunction("removeAllPhysics3DObjects", _SE(js_cocos2dx_physics3d_Physics3DWorld_removeAllPhysics3DObjects));
    cls->defineFunction("isDebugDrawEnabled", _SE(js_cocos2dx_physics3d_Physics3DWorld_isDebugDrawEnabled));
    cls->defineFunction("removeAllPhysics3DConstraints", _SE(js_cocos2dx_physics3d_Physics3DWorld_removeAllPhysics3DConstraints));
    cls->defineFunction("getGravity", _SE(js_cocos2dx_physics3d_Physics3DWorld_getGravity));
    cls->defineFunction("removePhysics3DConstraint", _SE(js_cocos2dx_physics3d_Physics3DWorld_removePhysics3DConstraint));
    cls->defineFunction("addPhysics3DObject", _SE(js_cocos2dx_physics3d_Physics3DWorld_addPhysics3DObject));
    cls->defineFunction("setDebugDrawEnable", _SE(js_cocos2dx_physics3d_Physics3DWorld_setDebugDrawEnable));
    cls->defineFunction("removePhysics3DObject", _SE(js_cocos2dx_physics3d_Physics3DWorld_removePhysics3DObject));
    cls->defineFunction("getPhysicsObject", _SE(js_cocos2dx_physics3d_Physics3DWorld_getPhysicsObject));
    cls->defineFunction("addPhysics3DConstraint", _SE(js_cocos2dx_physics3d_Physics3DWorld_addPhysics3DConstraint));
    cls->defineFunction("debugDraw", _SE(js_cocos2dx_physics3d_Physics3DWorld_debugDraw));
    cls->defineFunction("sweepShape", _SE(js_cocos2dx_physics3d_Physics3DWorld_sweepShape));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_physics3d_Physics3DWorld_create));
    cls->defineFinalizeFunction(_SE(js_cocos2d_Physics3DWorld_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Physics3DWorld>(cls);

    __jsb_cocos2d_Physics3DWorld_proto = cls->getProto();
    __jsb_cocos2d_Physics3DWorld_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_cocos2d_Physics3DConstraint_proto = nullptr;
se::Class* __jsb_cocos2d_Physics3DConstraint_class = nullptr;

static bool js_cocos2dx_physics3d_Physics3DConstraint_setEnabled(se::State& s)
{
    cocos2d::Physics3DConstraint* cobj = (cocos2d::Physics3DConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConstraint_setEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConstraint_setEnabled : Error processing arguments");
        cobj->setEnabled(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConstraint_setEnabled)

static bool js_cocos2dx_physics3d_Physics3DConstraint_setBreakingImpulse(se::State& s)
{
    cocos2d::Physics3DConstraint* cobj = (cocos2d::Physics3DConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConstraint_setBreakingImpulse : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConstraint_setBreakingImpulse : Error processing arguments");
        cobj->setBreakingImpulse(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConstraint_setBreakingImpulse)

static bool js_cocos2dx_physics3d_Physics3DConstraint_getUserData(se::State& s)
{
    cocos2d::Physics3DConstraint* cobj = (cocos2d::Physics3DConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConstraint_getUserData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        void* result = cobj->getUserData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConstraint_getUserData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConstraint_getUserData)

static bool js_cocos2dx_physics3d_Physics3DConstraint_getBreakingImpulse(se::State& s)
{
    cocos2d::Physics3DConstraint* cobj = (cocos2d::Physics3DConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConstraint_getBreakingImpulse : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getBreakingImpulse();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConstraint_getBreakingImpulse : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConstraint_getBreakingImpulse)

static bool js_cocos2dx_physics3d_Physics3DConstraint_getBodyA(se::State& s)
{
    cocos2d::Physics3DConstraint* cobj = (cocos2d::Physics3DConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConstraint_getBodyA : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Physics3DRigidBody* result = cobj->getBodyA();
        ok &= native_ptr_to_seval<cocos2d::Physics3DRigidBody>((cocos2d::Physics3DRigidBody*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConstraint_getBodyA : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConstraint_getBodyA)

static bool js_cocos2dx_physics3d_Physics3DConstraint_isEnabled(se::State& s)
{
    cocos2d::Physics3DConstraint* cobj = (cocos2d::Physics3DConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConstraint_isEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isEnabled();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConstraint_isEnabled : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConstraint_isEnabled)

static bool js_cocos2dx_physics3d_Physics3DConstraint_getOverrideNumSolverIterations(se::State& s)
{
    cocos2d::Physics3DConstraint* cobj = (cocos2d::Physics3DConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConstraint_getOverrideNumSolverIterations : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = cobj->getOverrideNumSolverIterations();
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConstraint_getOverrideNumSolverIterations : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConstraint_getOverrideNumSolverIterations)

static bool js_cocos2dx_physics3d_Physics3DConstraint_getBodyB(se::State& s)
{
    cocos2d::Physics3DConstraint* cobj = (cocos2d::Physics3DConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConstraint_getBodyB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Physics3DRigidBody* result = cobj->getBodyB();
        ok &= native_ptr_to_seval<cocos2d::Physics3DRigidBody>((cocos2d::Physics3DRigidBody*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConstraint_getBodyB : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConstraint_getBodyB)

static bool js_cocos2dx_physics3d_Physics3DConstraint_setOverrideNumSolverIterations(se::State& s)
{
    cocos2d::Physics3DConstraint* cobj = (cocos2d::Physics3DConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConstraint_setOverrideNumSolverIterations : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConstraint_setOverrideNumSolverIterations : Error processing arguments");
        cobj->setOverrideNumSolverIterations(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConstraint_setOverrideNumSolverIterations)

static bool js_cocos2dx_physics3d_Physics3DConstraint_getConstraintType(se::State& s)
{
    cocos2d::Physics3DConstraint* cobj = (cocos2d::Physics3DConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConstraint_getConstraintType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        int result = (int)cobj->getConstraintType();
        ok &= int32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConstraint_getConstraintType : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConstraint_getConstraintType)

static bool js_cocos2dx_physics3d_Physics3DConstraint_setUserData(se::State& s)
{
    cocos2d::Physics3DConstraint* cobj = (cocos2d::Physics3DConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConstraint_setUserData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        void* arg0 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR void*
        ok = false;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConstraint_setUserData : Error processing arguments");
        cobj->setUserData(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConstraint_setUserData)

static bool js_cocos2dx_physics3d_Physics3DConstraint_getbtContraint(se::State& s)
{
    cocos2d::Physics3DConstraint* cobj = (cocos2d::Physics3DConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConstraint_getbtContraint : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        btTypedConstraint* result = cobj->getbtContraint();
        ok &= native_ptr_to_seval<btTypedConstraint>((btTypedConstraint*)result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConstraint_getbtContraint : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConstraint_getbtContraint)



static bool js_cocos2d_Physics3DConstraint_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::Physics3DConstraint)", s.nativeThisObject());
    cocos2d::Physics3DConstraint* cobj = (cocos2d::Physics3DConstraint*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Physics3DConstraint_finalize)

bool js_register_cocos2dx_physics3d_Physics3DConstraint(se::Object* obj)
{
    auto cls = se::Class::create("Physics3DConstraint", obj, nullptr, nullptr);

    cls->defineFunction("setEnabled", _SE(js_cocos2dx_physics3d_Physics3DConstraint_setEnabled));
    cls->defineFunction("setBreakingImpulse", _SE(js_cocos2dx_physics3d_Physics3DConstraint_setBreakingImpulse));
    cls->defineFunction("getUserData", _SE(js_cocos2dx_physics3d_Physics3DConstraint_getUserData));
    cls->defineFunction("getBreakingImpulse", _SE(js_cocos2dx_physics3d_Physics3DConstraint_getBreakingImpulse));
    cls->defineFunction("getBodyA", _SE(js_cocos2dx_physics3d_Physics3DConstraint_getBodyA));
    cls->defineFunction("isEnabled", _SE(js_cocos2dx_physics3d_Physics3DConstraint_isEnabled));
    cls->defineFunction("getOverrideNumSolverIterations", _SE(js_cocos2dx_physics3d_Physics3DConstraint_getOverrideNumSolverIterations));
    cls->defineFunction("getBodyB", _SE(js_cocos2dx_physics3d_Physics3DConstraint_getBodyB));
    cls->defineFunction("setOverrideNumSolverIterations", _SE(js_cocos2dx_physics3d_Physics3DConstraint_setOverrideNumSolverIterations));
    cls->defineFunction("getConstraintType", _SE(js_cocos2dx_physics3d_Physics3DConstraint_getConstraintType));
    cls->defineFunction("setUserData", _SE(js_cocos2dx_physics3d_Physics3DConstraint_setUserData));
    cls->defineFunction("getbtContraint", _SE(js_cocos2dx_physics3d_Physics3DConstraint_getbtContraint));
    cls->defineFinalizeFunction(_SE(js_cocos2d_Physics3DConstraint_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Physics3DConstraint>(cls);

    __jsb_cocos2d_Physics3DConstraint_proto = cls->getProto();
    __jsb_cocos2d_Physics3DConstraint_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_cocos2d_Physics3DPointToPointConstraint_proto = nullptr;
se::Class* __jsb_cocos2d_Physics3DPointToPointConstraint_class = nullptr;

static bool js_cocos2dx_physics3d_Physics3DPointToPointConstraint_getPivotPointInA(se::State& s)
{
    cocos2d::Physics3DPointToPointConstraint* cobj = (cocos2d::Physics3DPointToPointConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DPointToPointConstraint_getPivotPointInA : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getPivotPointInA();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DPointToPointConstraint_getPivotPointInA : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DPointToPointConstraint_getPivotPointInA)

static bool js_cocos2dx_physics3d_Physics3DPointToPointConstraint_getPivotPointInB(se::State& s)
{
    cocos2d::Physics3DPointToPointConstraint* cobj = (cocos2d::Physics3DPointToPointConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DPointToPointConstraint_getPivotPointInB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getPivotPointInB();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DPointToPointConstraint_getPivotPointInB : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DPointToPointConstraint_getPivotPointInB)

static bool js_cocos2dx_physics3d_Physics3DPointToPointConstraint_init(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocos2d::Physics3DPointToPointConstraint* cobj = (cocos2d::Physics3DPointToPointConstraint*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_physics3d_Physics3DPointToPointConstraint_init : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 4) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DRigidBody* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg2;
            ok &= seval_to_Vec3(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg3;
            ok &= seval_to_Vec3(args[3], &arg3);
            if (!ok) { ok = true; break; }
            bool result = cobj->init(arg0, arg1, arg2, arg3);
            ok &= boolean_to_seval(result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DPointToPointConstraint_init : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg1;
            ok &= seval_to_Vec3(args[1], &arg1);
            if (!ok) { ok = true; break; }
            bool result = cobj->init(arg0, arg1);
            ok &= boolean_to_seval(result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DPointToPointConstraint_init : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DPointToPointConstraint_init)

static bool js_cocos2dx_physics3d_Physics3DPointToPointConstraint_setPivotPointInA(se::State& s)
{
    cocos2d::Physics3DPointToPointConstraint* cobj = (cocos2d::Physics3DPointToPointConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DPointToPointConstraint_setPivotPointInA : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DPointToPointConstraint_setPivotPointInA : Error processing arguments");
        cobj->setPivotPointInA(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DPointToPointConstraint_setPivotPointInA)

static bool js_cocos2dx_physics3d_Physics3DPointToPointConstraint_setPivotPointInB(se::State& s)
{
    cocos2d::Physics3DPointToPointConstraint* cobj = (cocos2d::Physics3DPointToPointConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DPointToPointConstraint_setPivotPointInB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DPointToPointConstraint_setPivotPointInB : Error processing arguments");
        cobj->setPivotPointInB(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DPointToPointConstraint_setPivotPointInB)

static bool js_cocos2dx_physics3d_Physics3DPointToPointConstraint_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 4) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DRigidBody* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg2;
            ok &= seval_to_Vec3(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg3;
            ok &= seval_to_Vec3(args[3], &arg3);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DPointToPointConstraint* result = cocos2d::Physics3DPointToPointConstraint::create(arg0, arg1, arg2, arg3);
            ok &= native_ptr_to_seval<cocos2d::Physics3DPointToPointConstraint>((cocos2d::Physics3DPointToPointConstraint*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DPointToPointConstraint_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 2) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg1;
            ok &= seval_to_Vec3(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DPointToPointConstraint* result = cocos2d::Physics3DPointToPointConstraint::create(arg0, arg1);
            ok &= native_ptr_to_seval<cocos2d::Physics3DPointToPointConstraint>((cocos2d::Physics3DPointToPointConstraint*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DPointToPointConstraint_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DPointToPointConstraint_create)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Physics3DPointToPointConstraint_finalize)

static bool js_cocos2dx_physics3d_Physics3DPointToPointConstraint_constructor(se::State& s)
{
    cocos2d::Physics3DPointToPointConstraint* cobj = new (std::nothrow) cocos2d::Physics3DPointToPointConstraint();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_physics3d_Physics3DPointToPointConstraint_constructor, __jsb_cocos2d_Physics3DPointToPointConstraint_class, js_cocos2d_Physics3DPointToPointConstraint_finalize)



extern se::Object* __jsb_cocos2d_Physics3DConstraint_proto;

static bool js_cocos2d_Physics3DPointToPointConstraint_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::Physics3DPointToPointConstraint)", s.nativeThisObject());
    cocos2d::Physics3DPointToPointConstraint* cobj = (cocos2d::Physics3DPointToPointConstraint*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Physics3DPointToPointConstraint_finalize)

bool js_register_cocos2dx_physics3d_Physics3DPointToPointConstraint(se::Object* obj)
{
    auto cls = se::Class::create("Physics3DPointToPointConstraint", obj, __jsb_cocos2d_Physics3DConstraint_proto, _SE(js_cocos2dx_physics3d_Physics3DPointToPointConstraint_constructor));

    cls->defineFunction("getPivotPointInA", _SE(js_cocos2dx_physics3d_Physics3DPointToPointConstraint_getPivotPointInA));
    cls->defineFunction("getPivotPointInB", _SE(js_cocos2dx_physics3d_Physics3DPointToPointConstraint_getPivotPointInB));
    cls->defineFunction("init", _SE(js_cocos2dx_physics3d_Physics3DPointToPointConstraint_init));
    cls->defineFunction("setPivotPointInA", _SE(js_cocos2dx_physics3d_Physics3DPointToPointConstraint_setPivotPointInA));
    cls->defineFunction("setPivotPointInB", _SE(js_cocos2dx_physics3d_Physics3DPointToPointConstraint_setPivotPointInB));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_physics3d_Physics3DPointToPointConstraint_create));
    cls->defineFinalizeFunction(_SE(js_cocos2d_Physics3DPointToPointConstraint_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Physics3DPointToPointConstraint>(cls);

    __jsb_cocos2d_Physics3DPointToPointConstraint_proto = cls->getProto();
    __jsb_cocos2d_Physics3DPointToPointConstraint_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_cocos2d_Physics3DHingeConstraint_proto = nullptr;
se::Class* __jsb_cocos2d_Physics3DHingeConstraint_class = nullptr;

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getHingeAngle(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getHingeAngle : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            cocos2d::Mat4 arg0;
            ok &= seval_to_Mat4(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Mat4 arg1;
            ok &= seval_to_Mat4(args[1], &arg1);
            if (!ok) { ok = true; break; }
            float result = cobj->getHingeAngle(arg0, arg1);
            ok &= float_to_seval(result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getHingeAngle : Error processing arguments");
            return true;
        }
    } while(false);

    do {
        if (argc == 0) {
            float result = cobj->getHingeAngle();
            ok &= float_to_seval(result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getHingeAngle : Error processing arguments");
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_getHingeAngle)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getMotorTargetVelosity(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getMotorTargetVelosity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getMotorTargetVelosity();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getMotorTargetVelosity : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_getMotorTargetVelosity)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getFrameOffsetA(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getFrameOffsetA : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Mat4 result = cobj->getFrameOffsetA();
        ok &= Mat4_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getFrameOffsetA : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_getFrameOffsetA)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getFrameOffsetB(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getFrameOffsetB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Mat4 result = cobj->getFrameOffsetB();
        ok &= Mat4_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getFrameOffsetB : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_getFrameOffsetB)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_setMaxMotorImpulse(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setMaxMotorImpulse : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setMaxMotorImpulse : Error processing arguments");
        cobj->setMaxMotorImpulse(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_setMaxMotorImpulse)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_enableAngularMotor(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_enableAngularMotor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        bool arg0;
        float arg1 = 0;
        float arg2 = 0;
        ok &= seval_to_boolean(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        ok &= seval_to_float(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_enableAngularMotor : Error processing arguments");
        cobj->enableAngularMotor(arg0, arg1, arg2);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 3);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_enableAngularMotor)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getUpperLimit(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getUpperLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getUpperLimit();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getUpperLimit : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_getUpperLimit)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getMaxMotorImpulse(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getMaxMotorImpulse : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getMaxMotorImpulse();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getMaxMotorImpulse : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_getMaxMotorImpulse)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getLowerLimit(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getLowerLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getLowerLimit();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getLowerLimit : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_getLowerLimit)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_setUseFrameOffset(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setUseFrameOffset : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setUseFrameOffset : Error processing arguments");
        cobj->setUseFrameOffset(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_setUseFrameOffset)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getEnableAngularMotor(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getEnableAngularMotor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getEnableAngularMotor();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getEnableAngularMotor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_getEnableAngularMotor)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_enableMotor(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_enableMotor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_enableMotor : Error processing arguments");
        cobj->enableMotor(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_enableMotor)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getBFrame(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getBFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Mat4 result = cobj->getBFrame();
        ok &= Mat4_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getBFrame : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_getBFrame)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_setFrames(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setFrames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocos2d::Mat4 arg0;
        cocos2d::Mat4 arg1;
        ok &= seval_to_Mat4(args[0], &arg0);
        ok &= seval_to_Mat4(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setFrames : Error processing arguments");
        cobj->setFrames(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_setFrames)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getUseFrameOffset(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getUseFrameOffset : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getUseFrameOffset();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getUseFrameOffset : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_getUseFrameOffset)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_setAngularOnly(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setAngularOnly : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setAngularOnly : Error processing arguments");
        cobj->setAngularOnly(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_setAngularOnly)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_setLimit(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setLimit : Error processing arguments");
        cobj->setLimit(arg0, arg1);
        return true;
    }
    if (argc == 3) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        ok &= seval_to_float(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setLimit : Error processing arguments");
        cobj->setLimit(arg0, arg1, arg2);
        return true;
    }
    if (argc == 4) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        ok &= seval_to_float(args[2], &arg2);
        ok &= seval_to_float(args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setLimit : Error processing arguments");
        cobj->setLimit(arg0, arg1, arg2, arg3);
        return true;
    }
    if (argc == 5) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        ok &= seval_to_float(args[2], &arg2);
        ok &= seval_to_float(args[3], &arg3);
        ok &= seval_to_float(args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setLimit : Error processing arguments");
        cobj->setLimit(arg0, arg1, arg2, arg3, arg4);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_setLimit)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_setMotorTarget(se::State& s)
{
    CC_UNUSED bool ok = true;
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2( cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setMotorTarget : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 2) {
            float arg0 = 0;
            ok &= seval_to_float(args[0], &arg0);
            if (!ok) { ok = true; break; }
            float arg1 = 0;
            ok &= seval_to_float(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cobj->setMotorTarget(arg0, arg1);
            return true;
        }
    } while(false);

    do {
        if (argc == 2) {
            cocos2d::Quaternion arg0;
            ok &= seval_to_Quaternion(args[0], &arg0);
            if (!ok) { ok = true; break; }
            float arg1 = 0;
            ok &= seval_to_float(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cobj->setMotorTarget(arg0, arg1);
            return true;
        }
    } while(false);

    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_setMotorTarget)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getAngularOnly(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getAngularOnly : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getAngularOnly();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getAngularOnly : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_getAngularOnly)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_setAxis(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setAxis : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_setAxis : Error processing arguments");
        cobj->setAxis(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_setAxis)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_getAFrame(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getAFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Mat4 result = cobj->getAFrame();
        ok &= Mat4_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_getAFrame : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_getAFrame)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 3) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg1;
            ok &= seval_to_Vec3(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg2;
            ok &= seval_to_Vec3(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DHingeConstraint* result = cocos2d::Physics3DHingeConstraint::create(arg0, arg1, arg2);
            ok &= native_ptr_to_seval<cocos2d::Physics3DHingeConstraint>((cocos2d::Physics3DHingeConstraint*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 4) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg1;
            ok &= seval_to_Vec3(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg2;
            ok &= seval_to_Vec3(args[2], &arg2);
            if (!ok) { ok = true; break; }
            bool arg3;
            ok &= seval_to_boolean(args[3], &arg3);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DHingeConstraint* result = cocos2d::Physics3DHingeConstraint::create(arg0, arg1, arg2, arg3);
            ok &= native_ptr_to_seval<cocos2d::Physics3DHingeConstraint>((cocos2d::Physics3DHingeConstraint*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 2) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Mat4 arg1;
            ok &= seval_to_Mat4(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DHingeConstraint* result = cocos2d::Physics3DHingeConstraint::create(arg0, arg1);
            ok &= native_ptr_to_seval<cocos2d::Physics3DHingeConstraint>((cocos2d::Physics3DHingeConstraint*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 3) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Mat4 arg1;
            ok &= seval_to_Mat4(args[1], &arg1);
            if (!ok) { ok = true; break; }
            bool arg2;
            ok &= seval_to_boolean(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DHingeConstraint* result = cocos2d::Physics3DHingeConstraint::create(arg0, arg1, arg2);
            ok &= native_ptr_to_seval<cocos2d::Physics3DHingeConstraint>((cocos2d::Physics3DHingeConstraint*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 6) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DRigidBody* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg2;
            ok &= seval_to_Vec3(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg3;
            ok &= seval_to_Vec3(args[3], &arg3);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg4;
            ok &= seval_to_Vec3(args[4], &arg4);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg5;
            ok &= seval_to_Vec3(args[5], &arg5);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DHingeConstraint* result = cocos2d::Physics3DHingeConstraint::create(arg0, arg1, arg2, arg3, arg4, arg5);
            ok &= native_ptr_to_seval<cocos2d::Physics3DHingeConstraint>((cocos2d::Physics3DHingeConstraint*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 7) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DRigidBody* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg2;
            ok &= seval_to_Vec3(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg3;
            ok &= seval_to_Vec3(args[3], &arg3);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg4;
            ok &= seval_to_Vec3(args[4], &arg4);
            if (!ok) { ok = true; break; }
            cocos2d::Vec3 arg5;
            ok &= seval_to_Vec3(args[5], &arg5);
            if (!ok) { ok = true; break; }
            bool arg6;
            ok &= seval_to_boolean(args[6], &arg6);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DHingeConstraint* result = cocos2d::Physics3DHingeConstraint::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
            ok &= native_ptr_to_seval<cocos2d::Physics3DHingeConstraint>((cocos2d::Physics3DHingeConstraint*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 4) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DRigidBody* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Mat4 arg2;
            ok &= seval_to_Mat4(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocos2d::Mat4 arg3;
            ok &= seval_to_Mat4(args[3], &arg3);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DHingeConstraint* result = cocos2d::Physics3DHingeConstraint::create(arg0, arg1, arg2, arg3);
            ok &= native_ptr_to_seval<cocos2d::Physics3DHingeConstraint>((cocos2d::Physics3DHingeConstraint*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 5) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DRigidBody* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Mat4 arg2;
            ok &= seval_to_Mat4(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocos2d::Mat4 arg3;
            ok &= seval_to_Mat4(args[3], &arg3);
            if (!ok) { ok = true; break; }
            bool arg4;
            ok &= seval_to_boolean(args[4], &arg4);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DHingeConstraint* result = cocos2d::Physics3DHingeConstraint::create(arg0, arg1, arg2, arg3, arg4);
            ok &= native_ptr_to_seval<cocos2d::Physics3DHingeConstraint>((cocos2d::Physics3DHingeConstraint*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DHingeConstraint_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DHingeConstraint_create)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Physics3DHingeConstraint_finalize)

static bool js_cocos2dx_physics3d_Physics3DHingeConstraint_constructor(se::State& s)
{
    cocos2d::Physics3DHingeConstraint* cobj = new (std::nothrow) cocos2d::Physics3DHingeConstraint();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_physics3d_Physics3DHingeConstraint_constructor, __jsb_cocos2d_Physics3DHingeConstraint_class, js_cocos2d_Physics3DHingeConstraint_finalize)



extern se::Object* __jsb_cocos2d_Physics3DConstraint_proto;

static bool js_cocos2d_Physics3DHingeConstraint_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::Physics3DHingeConstraint)", s.nativeThisObject());
    cocos2d::Physics3DHingeConstraint* cobj = (cocos2d::Physics3DHingeConstraint*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Physics3DHingeConstraint_finalize)

bool js_register_cocos2dx_physics3d_Physics3DHingeConstraint(se::Object* obj)
{
    auto cls = se::Class::create("Physics3DHingeConstraint", obj, __jsb_cocos2d_Physics3DConstraint_proto, _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_constructor));

    cls->defineFunction("getHingeAngle", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_getHingeAngle));
    cls->defineFunction("getMotorTargetVelosity", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_getMotorTargetVelosity));
    cls->defineFunction("getFrameOffsetA", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_getFrameOffsetA));
    cls->defineFunction("getFrameOffsetB", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_getFrameOffsetB));
    cls->defineFunction("setMaxMotorImpulse", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_setMaxMotorImpulse));
    cls->defineFunction("enableAngularMotor", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_enableAngularMotor));
    cls->defineFunction("getUpperLimit", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_getUpperLimit));
    cls->defineFunction("getMaxMotorImpulse", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_getMaxMotorImpulse));
    cls->defineFunction("getLowerLimit", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_getLowerLimit));
    cls->defineFunction("setUseFrameOffset", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_setUseFrameOffset));
    cls->defineFunction("getEnableAngularMotor", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_getEnableAngularMotor));
    cls->defineFunction("enableMotor", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_enableMotor));
    cls->defineFunction("getBFrame", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_getBFrame));
    cls->defineFunction("setFrames", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_setFrames));
    cls->defineFunction("getUseFrameOffset", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_getUseFrameOffset));
    cls->defineFunction("setAngularOnly", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_setAngularOnly));
    cls->defineFunction("setLimit", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_setLimit));
    cls->defineFunction("setMotorTarget", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_setMotorTarget));
    cls->defineFunction("getAngularOnly", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_getAngularOnly));
    cls->defineFunction("setAxis", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_setAxis));
    cls->defineFunction("getAFrame", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_getAFrame));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_physics3d_Physics3DHingeConstraint_create));
    cls->defineFinalizeFunction(_SE(js_cocos2d_Physics3DHingeConstraint_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Physics3DHingeConstraint>(cls);

    __jsb_cocos2d_Physics3DHingeConstraint_proto = cls->getProto();
    __jsb_cocos2d_Physics3DHingeConstraint_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_cocos2d_Physics3DSliderConstraint_proto = nullptr;
se::Class* __jsb_cocos2d_Physics3DSliderConstraint_class = nullptr;

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setPoweredAngMotor(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setPoweredAngMotor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setPoweredAngMotor : Error processing arguments");
        cobj->setPoweredAngMotor(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setPoweredAngMotor)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingLimAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingLimAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDampingLimAng();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingLimAng : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingLimAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionOrthoLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionOrthoLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionOrthoLin : Error processing arguments");
        cobj->setRestitutionOrthoLin(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionOrthoLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionDirLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionDirLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionDirLin : Error processing arguments");
        cobj->setRestitutionDirLin(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionDirLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getLinearPos(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getLinearPos : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getLinearPos();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getLinearPos : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getLinearPos)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getFrameOffsetA(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getFrameOffsetA : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Mat4 result = cobj->getFrameOffsetA();
        ok &= Mat4_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getFrameOffsetA : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getFrameOffsetA)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getFrameOffsetB(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getFrameOffsetB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Mat4 result = cobj->getFrameOffsetB();
        ok &= Mat4_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getFrameOffsetB : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getFrameOffsetB)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setPoweredLinMotor(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setPoweredLinMotor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setPoweredLinMotor : Error processing arguments");
        cobj->setPoweredLinMotor(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setPoweredLinMotor)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingDirAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingDirAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDampingDirAng();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingDirAng : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingDirAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionLimLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionLimLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRestitutionLimLin();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionLimLin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionLimLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessOrthoAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessOrthoAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSoftnessOrthoAng();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessOrthoAng : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessOrthoAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessOrthoLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessOrthoLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessOrthoLin : Error processing arguments");
        cobj->setSoftnessOrthoLin(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessOrthoLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessLimLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessLimLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessLimLin : Error processing arguments");
        cobj->setSoftnessLimLin(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessLimLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getAngularPos(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getAngularPos : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getAngularPos();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getAngularPos : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getAngularPos)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionLimAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionLimAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionLimAng : Error processing arguments");
        cobj->setRestitutionLimAng(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionLimAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setUpperLinLimit(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setUpperLinLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setUpperLinLimit : Error processing arguments");
        cobj->setUpperLinLimit(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setUpperLinLimit)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingDirLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingDirLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingDirLin : Error processing arguments");
        cobj->setDampingDirLin(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingDirLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getUpperAngLimit(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getUpperAngLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getUpperAngLimit();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getUpperAngLimit : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getUpperAngLimit)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingDirLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingDirLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDampingDirLin();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingDirLin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingDirLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessDirAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessDirAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSoftnessDirAng();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessDirAng : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessDirAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getPoweredAngMotor(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getPoweredAngMotor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getPoweredAngMotor();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getPoweredAngMotor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getPoweredAngMotor)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setLowerAngLimit(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setLowerAngLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setLowerAngLimit : Error processing arguments");
        cobj->setLowerAngLimit(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setLowerAngLimit)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setUpperAngLimit(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setUpperAngLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setUpperAngLimit : Error processing arguments");
        cobj->setUpperAngLimit(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setUpperAngLimit)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setTargetLinMotorVelocity(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setTargetLinMotorVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setTargetLinMotorVelocity : Error processing arguments");
        cobj->setTargetLinMotorVelocity(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setTargetLinMotorVelocity)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingLimAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingLimAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingLimAng : Error processing arguments");
        cobj->setDampingLimAng(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingLimAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionLimAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionLimAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRestitutionLimAng();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionLimAng : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionLimAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getUseFrameOffset(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getUseFrameOffset : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getUseFrameOffset();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getUseFrameOffset : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getUseFrameOffset)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessOrthoLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessOrthoLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSoftnessOrthoLin();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessOrthoLin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessOrthoLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingOrthoAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingOrthoAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDampingOrthoAng();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingOrthoAng : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingOrthoAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setUseFrameOffset(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setUseFrameOffset : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setUseFrameOffset : Error processing arguments");
        cobj->setUseFrameOffset(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setUseFrameOffset)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setLowerLinLimit(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setLowerLinLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setLowerLinLimit : Error processing arguments");
        cobj->setLowerLinLimit(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setLowerLinLimit)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionDirLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionDirLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRestitutionDirLin();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionDirLin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionDirLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getTargetLinMotorVelocity(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getTargetLinMotorVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTargetLinMotorVelocity();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getTargetLinMotorVelocity : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getTargetLinMotorVelocity)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getLowerLinLimit(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getLowerLinLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getLowerLinLimit();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getLowerLinLimit : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getLowerLinLimit)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessLimLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessLimLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSoftnessLimLin();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessLimLin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessLimLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingOrthoAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingOrthoAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingOrthoAng : Error processing arguments");
        cobj->setDampingOrthoAng(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingOrthoAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessDirAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessDirAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessDirAng : Error processing arguments");
        cobj->setSoftnessDirAng(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessDirAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getPoweredLinMotor(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getPoweredLinMotor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getPoweredLinMotor();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getPoweredLinMotor : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getPoweredLinMotor)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionOrthoAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionOrthoAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionOrthoAng : Error processing arguments");
        cobj->setRestitutionOrthoAng(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionOrthoAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingDirAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingDirAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingDirAng : Error processing arguments");
        cobj->setDampingDirAng(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingDirAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setFrames(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setFrames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocos2d::Mat4 arg0;
        cocos2d::Mat4 arg1;
        ok &= seval_to_Mat4(args[0], &arg0);
        ok &= seval_to_Mat4(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setFrames : Error processing arguments");
        cobj->setFrames(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setFrames)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionOrthoAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionOrthoAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRestitutionOrthoAng();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionOrthoAng : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionOrthoAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getMaxAngMotorForce(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getMaxAngMotorForce : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getMaxAngMotorForce();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getMaxAngMotorForce : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getMaxAngMotorForce)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingOrthoLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingOrthoLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDampingOrthoLin();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingOrthoLin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingOrthoLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getUpperLinLimit(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getUpperLinLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getUpperLinLimit();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getUpperLinLimit : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getUpperLinLimit)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setMaxLinMotorForce(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setMaxLinMotorForce : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setMaxLinMotorForce : Error processing arguments");
        cobj->setMaxLinMotorForce(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setMaxLinMotorForce)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionOrthoLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionOrthoLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRestitutionOrthoLin();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionOrthoLin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionOrthoLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setTargetAngMotorVelocity(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setTargetAngMotorVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setTargetAngMotorVelocity : Error processing arguments");
        cobj->setTargetAngMotorVelocity(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setTargetAngMotorVelocity)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessLimAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessLimAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSoftnessLimAng();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessLimAng : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessLimAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionDirAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionDirAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionDirAng : Error processing arguments");
        cobj->setRestitutionDirAng(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionDirAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingLimLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingLimLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getDampingLimLin();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingLimLin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingLimLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getLowerAngLimit(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getLowerAngLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getLowerAngLimit();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getLowerAngLimit : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getLowerAngLimit)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionDirAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionDirAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRestitutionDirAng();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionDirAng : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionDirAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getTargetAngMotorVelocity(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getTargetAngMotorVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTargetAngMotorVelocity();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getTargetAngMotorVelocity : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getTargetAngMotorVelocity)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionLimLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionLimLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionLimLin : Error processing arguments");
        cobj->setRestitutionLimLin(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionLimLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getMaxLinMotorForce(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getMaxLinMotorForce : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getMaxLinMotorForce();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getMaxLinMotorForce : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getMaxLinMotorForce)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingOrthoLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingOrthoLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingOrthoLin : Error processing arguments");
        cobj->setDampingOrthoLin(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingOrthoLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessOrthoAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessOrthoAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessOrthoAng : Error processing arguments");
        cobj->setSoftnessOrthoAng(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessOrthoAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingLimLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingLimLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingLimLin : Error processing arguments");
        cobj->setDampingLimLin(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingLimLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessDirLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessDirLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessDirLin : Error processing arguments");
        cobj->setSoftnessDirLin(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessDirLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setMaxAngMotorForce(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setMaxAngMotorForce : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setMaxAngMotorForce : Error processing arguments");
        cobj->setMaxAngMotorForce(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setMaxAngMotorForce)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessDirLin(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessDirLin : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSoftnessDirLin();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessDirLin : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessDirLin)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessLimAng(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessLimAng : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessLimAng : Error processing arguments");
        cobj->setSoftnessLimAng(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessLimAng)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_getUseLinearReferenceFrameA(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getUseLinearReferenceFrameA : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getUseLinearReferenceFrameA();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_getUseLinearReferenceFrameA : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_getUseLinearReferenceFrameA)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 5) {
        cocos2d::Physics3DRigidBody* arg0 = nullptr;
        cocos2d::Physics3DRigidBody* arg1 = nullptr;
        cocos2d::Mat4 arg2;
        cocos2d::Mat4 arg3;
        bool arg4;
        ok &= seval_to_native_ptr(args[0], &arg0);
        ok &= seval_to_native_ptr(args[1], &arg1);
        ok &= seval_to_Mat4(args[2], &arg2);
        ok &= seval_to_Mat4(args[3], &arg3);
        ok &= seval_to_boolean(args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DSliderConstraint_create : Error processing arguments");
        auto result = cocos2d::Physics3DSliderConstraint::create(arg0, arg1, arg2, arg3, arg4);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_Physics3DSliderConstraint_class);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 5);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DSliderConstraint_create)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Physics3DSliderConstraint_finalize)

static bool js_cocos2dx_physics3d_Physics3DSliderConstraint_constructor(se::State& s)
{
    cocos2d::Physics3DSliderConstraint* cobj = new (std::nothrow) cocos2d::Physics3DSliderConstraint();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_physics3d_Physics3DSliderConstraint_constructor, __jsb_cocos2d_Physics3DSliderConstraint_class, js_cocos2d_Physics3DSliderConstraint_finalize)



extern se::Object* __jsb_cocos2d_Physics3DConstraint_proto;

static bool js_cocos2d_Physics3DSliderConstraint_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::Physics3DSliderConstraint)", s.nativeThisObject());
    cocos2d::Physics3DSliderConstraint* cobj = (cocos2d::Physics3DSliderConstraint*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Physics3DSliderConstraint_finalize)

bool js_register_cocos2dx_physics3d_Physics3DSliderConstraint(se::Object* obj)
{
    auto cls = se::Class::create("Physics3DSliderConstraint", obj, __jsb_cocos2d_Physics3DConstraint_proto, _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_constructor));

    cls->defineFunction("setPoweredAngMotor", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setPoweredAngMotor));
    cls->defineFunction("getDampingLimAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingLimAng));
    cls->defineFunction("setRestitutionOrthoLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionOrthoLin));
    cls->defineFunction("setRestitutionDirLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionDirLin));
    cls->defineFunction("getLinearPos", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getLinearPos));
    cls->defineFunction("getFrameOffsetA", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getFrameOffsetA));
    cls->defineFunction("getFrameOffsetB", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getFrameOffsetB));
    cls->defineFunction("setPoweredLinMotor", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setPoweredLinMotor));
    cls->defineFunction("getDampingDirAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingDirAng));
    cls->defineFunction("getRestitutionLimLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionLimLin));
    cls->defineFunction("getSoftnessOrthoAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessOrthoAng));
    cls->defineFunction("setSoftnessOrthoLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessOrthoLin));
    cls->defineFunction("setSoftnessLimLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessLimLin));
    cls->defineFunction("getAngularPos", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getAngularPos));
    cls->defineFunction("setRestitutionLimAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionLimAng));
    cls->defineFunction("setUpperLinLimit", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setUpperLinLimit));
    cls->defineFunction("setDampingDirLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingDirLin));
    cls->defineFunction("getUpperAngLimit", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getUpperAngLimit));
    cls->defineFunction("getDampingDirLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingDirLin));
    cls->defineFunction("getSoftnessDirAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessDirAng));
    cls->defineFunction("getPoweredAngMotor", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getPoweredAngMotor));
    cls->defineFunction("setLowerAngLimit", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setLowerAngLimit));
    cls->defineFunction("setUpperAngLimit", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setUpperAngLimit));
    cls->defineFunction("setTargetLinMotorVelocity", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setTargetLinMotorVelocity));
    cls->defineFunction("setDampingLimAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingLimAng));
    cls->defineFunction("getRestitutionLimAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionLimAng));
    cls->defineFunction("getUseFrameOffset", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getUseFrameOffset));
    cls->defineFunction("getSoftnessOrthoLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessOrthoLin));
    cls->defineFunction("getDampingOrthoAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingOrthoAng));
    cls->defineFunction("setUseFrameOffset", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setUseFrameOffset));
    cls->defineFunction("setLowerLinLimit", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setLowerLinLimit));
    cls->defineFunction("getRestitutionDirLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionDirLin));
    cls->defineFunction("getTargetLinMotorVelocity", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getTargetLinMotorVelocity));
    cls->defineFunction("getLowerLinLimit", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getLowerLinLimit));
    cls->defineFunction("getSoftnessLimLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessLimLin));
    cls->defineFunction("setDampingOrthoAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingOrthoAng));
    cls->defineFunction("setSoftnessDirAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessDirAng));
    cls->defineFunction("getPoweredLinMotor", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getPoweredLinMotor));
    cls->defineFunction("setRestitutionOrthoAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionOrthoAng));
    cls->defineFunction("setDampingDirAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingDirAng));
    cls->defineFunction("setFrames", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setFrames));
    cls->defineFunction("getRestitutionOrthoAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionOrthoAng));
    cls->defineFunction("getMaxAngMotorForce", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getMaxAngMotorForce));
    cls->defineFunction("getDampingOrthoLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingOrthoLin));
    cls->defineFunction("getUpperLinLimit", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getUpperLinLimit));
    cls->defineFunction("setMaxLinMotorForce", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setMaxLinMotorForce));
    cls->defineFunction("getRestitutionOrthoLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionOrthoLin));
    cls->defineFunction("setTargetAngMotorVelocity", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setTargetAngMotorVelocity));
    cls->defineFunction("getSoftnessLimAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessLimAng));
    cls->defineFunction("setRestitutionDirAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionDirAng));
    cls->defineFunction("getDampingLimLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getDampingLimLin));
    cls->defineFunction("getLowerAngLimit", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getLowerAngLimit));
    cls->defineFunction("getRestitutionDirAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getRestitutionDirAng));
    cls->defineFunction("getTargetAngMotorVelocity", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getTargetAngMotorVelocity));
    cls->defineFunction("setRestitutionLimLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setRestitutionLimLin));
    cls->defineFunction("getMaxLinMotorForce", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getMaxLinMotorForce));
    cls->defineFunction("setDampingOrthoLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingOrthoLin));
    cls->defineFunction("setSoftnessOrthoAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessOrthoAng));
    cls->defineFunction("setDampingLimLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setDampingLimLin));
    cls->defineFunction("setSoftnessDirLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessDirLin));
    cls->defineFunction("setMaxAngMotorForce", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setMaxAngMotorForce));
    cls->defineFunction("getSoftnessDirLin", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getSoftnessDirLin));
    cls->defineFunction("setSoftnessLimAng", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_setSoftnessLimAng));
    cls->defineFunction("getUseLinearReferenceFrameA", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_getUseLinearReferenceFrameA));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_physics3d_Physics3DSliderConstraint_create));
    cls->defineFinalizeFunction(_SE(js_cocos2d_Physics3DSliderConstraint_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Physics3DSliderConstraint>(cls);

    __jsb_cocos2d_Physics3DSliderConstraint_proto = cls->getProto();
    __jsb_cocos2d_Physics3DSliderConstraint_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_cocos2d_Physics3DConeTwistConstraint_proto = nullptr;
se::Class* __jsb_cocos2d_Physics3DConeTwistConstraint_class = nullptr;

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getBFrame(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getBFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Mat4 result = cobj->getBFrame();
        ok &= Mat4_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getBFrame : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getBFrame)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setFixThresh(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setFixThresh : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setFixThresh : Error processing arguments");
        cobj->setFixThresh(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setFixThresh)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFrameOffsetB(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFrameOffsetB : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Mat4 result = cobj->getFrameOffsetB();
        ok &= Mat4_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFrameOffsetB : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFrameOffsetB)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFrameOffsetA(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFrameOffsetA : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Mat4 result = cobj->getFrameOffsetA();
        ok &= Mat4_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFrameOffsetA : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFrameOffsetA)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFixThresh(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFixThresh : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getFixThresh();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFixThresh : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFixThresh)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getSwingSpan2(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getSwingSpan2 : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSwingSpan2();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getSwingSpan2 : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getSwingSpan2)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getSwingSpan1(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getSwingSpan1 : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSwingSpan1();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getSwingSpan1 : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getSwingSpan1)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setMaxMotorImpulse(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setMaxMotorImpulse : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setMaxMotorImpulse : Error processing arguments");
        cobj->setMaxMotorImpulse(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setMaxMotorImpulse)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setFrames(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setFrames : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        cocos2d::Mat4 arg0;
        cocos2d::Mat4 arg1;
        ok &= seval_to_Mat4(args[0], &arg0);
        ok &= seval_to_Mat4(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setFrames : Error processing arguments");
        cobj->setFrames(arg0, arg1);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setFrames)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getTwistAngle(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getTwistAngle : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTwistAngle();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getTwistAngle : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getTwistAngle)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_GetPointForAngle(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_GetPointForAngle : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_GetPointForAngle : Error processing arguments");
        cocos2d::Vec3 result = cobj->GetPointForAngle(arg0, arg1);
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_GetPointForAngle : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_GetPointForAngle)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setMaxMotorImpulseNormalized(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setMaxMotorImpulseNormalized : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setMaxMotorImpulseNormalized : Error processing arguments");
        cobj->setMaxMotorImpulseNormalized(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setMaxMotorImpulseNormalized)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getTwistSpan(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getTwistSpan : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getTwistSpan();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getTwistSpan : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getTwistSpan)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setDamping(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setDamping : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setDamping : Error processing arguments");
        cobj->setDamping(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setDamping)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setLimit(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 3) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        ok &= seval_to_float(args[2], &arg2);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setLimit : Error processing arguments");
        cobj->setLimit(arg0, arg1, arg2);
        return true;
    }
    if (argc == 4) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        ok &= seval_to_float(args[2], &arg2);
        ok &= seval_to_float(args[3], &arg3);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setLimit : Error processing arguments");
        cobj->setLimit(arg0, arg1, arg2, arg3);
        return true;
    }
    if (argc == 5) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        ok &= seval_to_float(args[2], &arg2);
        ok &= seval_to_float(args[3], &arg3);
        ok &= seval_to_float(args[4], &arg4);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setLimit : Error processing arguments");
        cobj->setLimit(arg0, arg1, arg2, arg3, arg4);
        return true;
    }
    if (argc == 6) {
        float arg0 = 0;
        float arg1 = 0;
        float arg2 = 0;
        float arg3 = 0;
        float arg4 = 0;
        float arg5 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        ok &= seval_to_float(args[2], &arg2);
        ok &= seval_to_float(args[3], &arg3);
        ok &= seval_to_float(args[4], &arg4);
        ok &= seval_to_float(args[5], &arg5);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setLimit : Error processing arguments");
        cobj->setLimit(arg0, arg1, arg2, arg3, arg4, arg5);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 6);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setLimit)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getAFrame(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getAFrame : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Mat4 result = cobj->getAFrame();
        ok &= Mat4_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getAFrame : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getAFrame)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_enableMotor(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_enableMotor : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_enableMotor : Error processing arguments");
        cobj->enableMotor(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_enableMotor)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 4) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DRigidBody* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Mat4 arg2;
            ok &= seval_to_Mat4(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocos2d::Mat4 arg3;
            ok &= seval_to_Mat4(args[3], &arg3);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DConeTwistConstraint* result = cocos2d::Physics3DConeTwistConstraint::create(arg0, arg1, arg2, arg3);
            ok &= native_ptr_to_seval<cocos2d::Physics3DConeTwistConstraint>((cocos2d::Physics3DConeTwistConstraint*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 2) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Mat4 arg1;
            ok &= seval_to_Mat4(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DConeTwistConstraint* result = cocos2d::Physics3DConeTwistConstraint::create(arg0, arg1);
            ok &= native_ptr_to_seval<cocos2d::Physics3DConeTwistConstraint>((cocos2d::Physics3DConeTwistConstraint*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3DConeTwistConstraint_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_create)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Physics3DConeTwistConstraint_finalize)

static bool js_cocos2dx_physics3d_Physics3DConeTwistConstraint_constructor(se::State& s)
{
    cocos2d::Physics3DConeTwistConstraint* cobj = new (std::nothrow) cocos2d::Physics3DConeTwistConstraint();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_constructor, __jsb_cocos2d_Physics3DConeTwistConstraint_class, js_cocos2d_Physics3DConeTwistConstraint_finalize)



extern se::Object* __jsb_cocos2d_Physics3DConstraint_proto;

static bool js_cocos2d_Physics3DConeTwistConstraint_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::Physics3DConeTwistConstraint)", s.nativeThisObject());
    cocos2d::Physics3DConeTwistConstraint* cobj = (cocos2d::Physics3DConeTwistConstraint*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Physics3DConeTwistConstraint_finalize)

bool js_register_cocos2dx_physics3d_Physics3DConeTwistConstraint(se::Object* obj)
{
    auto cls = se::Class::create("Physics3DConeTwistConstraint", obj, __jsb_cocos2d_Physics3DConstraint_proto, _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_constructor));

    cls->defineFunction("getBFrame", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getBFrame));
    cls->defineFunction("setFixThresh", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setFixThresh));
    cls->defineFunction("getFrameOffsetB", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFrameOffsetB));
    cls->defineFunction("getFrameOffsetA", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFrameOffsetA));
    cls->defineFunction("getFixThresh", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getFixThresh));
    cls->defineFunction("getSwingSpan2", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getSwingSpan2));
    cls->defineFunction("getSwingSpan1", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getSwingSpan1));
    cls->defineFunction("setMaxMotorImpulse", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setMaxMotorImpulse));
    cls->defineFunction("setFrames", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setFrames));
    cls->defineFunction("getTwistAngle", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getTwistAngle));
    cls->defineFunction("GetPointForAngle", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_GetPointForAngle));
    cls->defineFunction("setMaxMotorImpulseNormalized", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setMaxMotorImpulseNormalized));
    cls->defineFunction("getTwistSpan", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getTwistSpan));
    cls->defineFunction("setDamping", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setDamping));
    cls->defineFunction("setLimit", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_setLimit));
    cls->defineFunction("getAFrame", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_getAFrame));
    cls->defineFunction("enableMotor", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_enableMotor));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_physics3d_Physics3DConeTwistConstraint_create));
    cls->defineFinalizeFunction(_SE(js_cocos2d_Physics3DConeTwistConstraint_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Physics3DConeTwistConstraint>(cls);

    __jsb_cocos2d_Physics3DConeTwistConstraint_proto = cls->getProto();
    __jsb_cocos2d_Physics3DConeTwistConstraint_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_cocos2d_Physics3D6DofConstraint_proto = nullptr;
se::Class* __jsb_cocos2d_Physics3D6DofConstraint_class = nullptr;

static bool js_cocos2dx_physics3d_Physics3D6DofConstraint_setLinearLowerLimit(se::State& s)
{
    cocos2d::Physics3D6DofConstraint* cobj = (cocos2d::Physics3D6DofConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_setLinearLowerLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_setLinearLowerLimit : Error processing arguments");
        cobj->setLinearLowerLimit(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3D6DofConstraint_setLinearLowerLimit)

static bool js_cocos2dx_physics3d_Physics3D6DofConstraint_getLinearLowerLimit(se::State& s)
{
    cocos2d::Physics3D6DofConstraint* cobj = (cocos2d::Physics3D6DofConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_getLinearLowerLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getLinearLowerLimit();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_getLinearLowerLimit : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3D6DofConstraint_getLinearLowerLimit)

static bool js_cocos2dx_physics3d_Physics3D6DofConstraint_getAngularUpperLimit(se::State& s)
{
    cocos2d::Physics3D6DofConstraint* cobj = (cocos2d::Physics3D6DofConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_getAngularUpperLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getAngularUpperLimit();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_getAngularUpperLimit : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3D6DofConstraint_getAngularUpperLimit)

static bool js_cocos2dx_physics3d_Physics3D6DofConstraint_getUseFrameOffset(se::State& s)
{
    cocos2d::Physics3D6DofConstraint* cobj = (cocos2d::Physics3D6DofConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_getUseFrameOffset : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->getUseFrameOffset();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_getUseFrameOffset : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3D6DofConstraint_getUseFrameOffset)

static bool js_cocos2dx_physics3d_Physics3D6DofConstraint_getLinearUpperLimit(se::State& s)
{
    cocos2d::Physics3D6DofConstraint* cobj = (cocos2d::Physics3D6DofConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_getLinearUpperLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getLinearUpperLimit();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_getLinearUpperLimit : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3D6DofConstraint_getLinearUpperLimit)

static bool js_cocos2dx_physics3d_Physics3D6DofConstraint_setAngularLowerLimit(se::State& s)
{
    cocos2d::Physics3D6DofConstraint* cobj = (cocos2d::Physics3D6DofConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_setAngularLowerLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_setAngularLowerLimit : Error processing arguments");
        cobj->setAngularLowerLimit(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3D6DofConstraint_setAngularLowerLimit)

static bool js_cocos2dx_physics3d_Physics3D6DofConstraint_isLimited(se::State& s)
{
    cocos2d::Physics3D6DofConstraint* cobj = (cocos2d::Physics3D6DofConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_isLimited : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        int arg0 = 0;
        do { int32_t tmp = 0; ok &= seval_to_int32(args[0], &tmp); arg0 = (int)tmp; } while(false);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_isLimited : Error processing arguments");
        bool result = cobj->isLimited(arg0);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_isLimited : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3D6DofConstraint_isLimited)

static bool js_cocos2dx_physics3d_Physics3D6DofConstraint_setUseFrameOffset(se::State& s)
{
    cocos2d::Physics3D6DofConstraint* cobj = (cocos2d::Physics3D6DofConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_setUseFrameOffset : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_setUseFrameOffset : Error processing arguments");
        cobj->setUseFrameOffset(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3D6DofConstraint_setUseFrameOffset)

static bool js_cocos2dx_physics3d_Physics3D6DofConstraint_setLinearUpperLimit(se::State& s)
{
    cocos2d::Physics3D6DofConstraint* cobj = (cocos2d::Physics3D6DofConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_setLinearUpperLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_setLinearUpperLimit : Error processing arguments");
        cobj->setLinearUpperLimit(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3D6DofConstraint_setLinearUpperLimit)

static bool js_cocos2dx_physics3d_Physics3D6DofConstraint_getAngularLowerLimit(se::State& s)
{
    cocos2d::Physics3D6DofConstraint* cobj = (cocos2d::Physics3D6DofConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_getAngularLowerLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getAngularLowerLimit();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_getAngularLowerLimit : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3D6DofConstraint_getAngularLowerLimit)

static bool js_cocos2dx_physics3d_Physics3D6DofConstraint_setAngularUpperLimit(se::State& s)
{
    cocos2d::Physics3D6DofConstraint* cobj = (cocos2d::Physics3D6DofConstraint*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_setAngularUpperLimit : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_setAngularUpperLimit : Error processing arguments");
        cobj->setAngularUpperLimit(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3D6DofConstraint_setAngularUpperLimit)

static bool js_cocos2dx_physics3d_Physics3D6DofConstraint_create(se::State& s)
{
    CC_UNUSED bool ok = true;
    const auto& args = s.args();
    size_t argc = args.size();
    do {
        if (argc == 3) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Mat4 arg1;
            ok &= seval_to_Mat4(args[1], &arg1);
            if (!ok) { ok = true; break; }
            bool arg2;
            ok &= seval_to_boolean(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3D6DofConstraint* result = cocos2d::Physics3D6DofConstraint::create(arg0, arg1, arg2);
            ok &= native_ptr_to_seval<cocos2d::Physics3D6DofConstraint>((cocos2d::Physics3D6DofConstraint*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_create : Error processing arguments");
            return true;
        }
    } while (false);
    do {
        if (argc == 5) {
            cocos2d::Physics3DRigidBody* arg0 = nullptr;
            ok &= seval_to_native_ptr(args[0], &arg0);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3DRigidBody* arg1 = nullptr;
            ok &= seval_to_native_ptr(args[1], &arg1);
            if (!ok) { ok = true; break; }
            cocos2d::Mat4 arg2;
            ok &= seval_to_Mat4(args[2], &arg2);
            if (!ok) { ok = true; break; }
            cocos2d::Mat4 arg3;
            ok &= seval_to_Mat4(args[3], &arg3);
            if (!ok) { ok = true; break; }
            bool arg4;
            ok &= seval_to_boolean(args[4], &arg4);
            if (!ok) { ok = true; break; }
            cocos2d::Physics3D6DofConstraint* result = cocos2d::Physics3D6DofConstraint::create(arg0, arg1, arg2, arg3, arg4);
            ok &= native_ptr_to_seval<cocos2d::Physics3D6DofConstraint>((cocos2d::Physics3D6DofConstraint*)result, &s.rval());
            SE_PRECONDITION2(ok, false, "js_cocos2dx_physics3d_Physics3D6DofConstraint_create : Error processing arguments");
            return true;
        }
    } while (false);
    SE_REPORT_ERROR("wrong number of arguments: %d", (int)argc);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_physics3d_Physics3D6DofConstraint_create)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_Physics3D6DofConstraint_finalize)

static bool js_cocos2dx_physics3d_Physics3D6DofConstraint_constructor(se::State& s)
{
    cocos2d::Physics3D6DofConstraint* cobj = new (std::nothrow) cocos2d::Physics3D6DofConstraint();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_physics3d_Physics3D6DofConstraint_constructor, __jsb_cocos2d_Physics3D6DofConstraint_class, js_cocos2d_Physics3D6DofConstraint_finalize)



extern se::Object* __jsb_cocos2d_Physics3DConstraint_proto;

static bool js_cocos2d_Physics3D6DofConstraint_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::Physics3D6DofConstraint)", s.nativeThisObject());
    cocos2d::Physics3D6DofConstraint* cobj = (cocos2d::Physics3D6DofConstraint*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_Physics3D6DofConstraint_finalize)

bool js_register_cocos2dx_physics3d_Physics3D6DofConstraint(se::Object* obj)
{
    auto cls = se::Class::create("Physics3D6DofConstraint", obj, __jsb_cocos2d_Physics3DConstraint_proto, _SE(js_cocos2dx_physics3d_Physics3D6DofConstraint_constructor));

    cls->defineFunction("setLinearLowerLimit", _SE(js_cocos2dx_physics3d_Physics3D6DofConstraint_setLinearLowerLimit));
    cls->defineFunction("getLinearLowerLimit", _SE(js_cocos2dx_physics3d_Physics3D6DofConstraint_getLinearLowerLimit));
    cls->defineFunction("getAngularUpperLimit", _SE(js_cocos2dx_physics3d_Physics3D6DofConstraint_getAngularUpperLimit));
    cls->defineFunction("getUseFrameOffset", _SE(js_cocos2dx_physics3d_Physics3D6DofConstraint_getUseFrameOffset));
    cls->defineFunction("getLinearUpperLimit", _SE(js_cocos2dx_physics3d_Physics3D6DofConstraint_getLinearUpperLimit));
    cls->defineFunction("setAngularLowerLimit", _SE(js_cocos2dx_physics3d_Physics3D6DofConstraint_setAngularLowerLimit));
    cls->defineFunction("isLimited", _SE(js_cocos2dx_physics3d_Physics3D6DofConstraint_isLimited));
    cls->defineFunction("setUseFrameOffset", _SE(js_cocos2dx_physics3d_Physics3D6DofConstraint_setUseFrameOffset));
    cls->defineFunction("setLinearUpperLimit", _SE(js_cocos2dx_physics3d_Physics3D6DofConstraint_setLinearUpperLimit));
    cls->defineFunction("getAngularLowerLimit", _SE(js_cocos2dx_physics3d_Physics3D6DofConstraint_getAngularLowerLimit));
    cls->defineFunction("setAngularUpperLimit", _SE(js_cocos2dx_physics3d_Physics3D6DofConstraint_setAngularUpperLimit));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_physics3d_Physics3D6DofConstraint_create));
    cls->defineFinalizeFunction(_SE(js_cocos2d_Physics3D6DofConstraint_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::Physics3D6DofConstraint>(cls);

    __jsb_cocos2d_Physics3D6DofConstraint_proto = cls->getProto();
    __jsb_cocos2d_Physics3D6DofConstraint_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_cocos2dx_physics3d(se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("jsb", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject());
        nsVal.setObject(jsobj);
        obj->setProperty("jsb", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_cocos2dx_physics3d_Physics3DConstraint(ns);
    js_register_cocos2dx_physics3d_Physics3D6DofConstraint(ns);
    js_register_cocos2dx_physics3d_Physics3DObject(ns);
    js_register_cocos2dx_physics3d_Physics3DRigidBody(ns);
    js_register_cocos2dx_physics3d_Physics3DWorld(ns);
    js_register_cocos2dx_physics3d_Physics3DSliderConstraint(ns);
    js_register_cocos2dx_physics3d_Physics3DComponent(ns);
    js_register_cocos2dx_physics3d_Physics3DConeTwistConstraint(ns);
    js_register_cocos2dx_physics3d_Physics3DPointToPointConstraint(ns);
    js_register_cocos2dx_physics3d_PhysicsSprite3D(ns);
    js_register_cocos2dx_physics3d_Physics3DHingeConstraint(ns);
    js_register_cocos2dx_physics3d_Physics3DShape(ns);
    return true;
}

#endif //#if CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION
