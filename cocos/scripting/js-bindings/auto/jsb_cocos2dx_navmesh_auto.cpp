#include "scripting/js-bindings/auto/jsb_cocos2dx_navmesh_auto.hpp"
#if CC_USE_NAVMESH
#include "scripting/js-bindings/manual/jsb_conversions.hpp"
#include "scripting/js-bindings/manual/jsb_global.h"
#include "navmesh/CCNavMesh.h"
#include "scripting/js-bindings/manual/navmesh/jsb_cocos2dx_navmesh_conversions.h"

se::Object* __jsb_cocos2d_NavMeshAgent_proto = nullptr;
se::Class* __jsb_cocos2d_NavMeshAgent_class = nullptr;

static bool js_cocos2dx_navmesh_NavMeshAgent_setMaxSpeed(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_setMaxSpeed : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_setMaxSpeed : Error processing arguments");
        cobj->setMaxSpeed(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_setMaxSpeed)

static bool js_cocos2dx_navmesh_NavMeshAgent_syncToNode(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_syncToNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->syncToNode();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_syncToNode)

static bool js_cocos2dx_navmesh_NavMeshAgent_completeOffMeshLink(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_completeOffMeshLink : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->completeOffMeshLink();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_completeOffMeshLink)

static bool js_cocos2dx_navmesh_NavMeshAgent_getSeparationWeight(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_getSeparationWeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getSeparationWeight();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_getSeparationWeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_getSeparationWeight)

static bool js_cocos2dx_navmesh_NavMeshAgent_setAutoTraverseOffMeshLink(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_setAutoTraverseOffMeshLink : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_setAutoTraverseOffMeshLink : Error processing arguments");
        cobj->setAutoTraverseOffMeshLink(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_setAutoTraverseOffMeshLink)

static bool js_cocos2dx_navmesh_NavMeshAgent_getCurrentVelocity(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_getCurrentVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getCurrentVelocity();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_getCurrentVelocity : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_getCurrentVelocity)

static bool js_cocos2dx_navmesh_NavMeshAgent_syncToAgent(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_syncToAgent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->syncToAgent();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_syncToAgent)

static bool js_cocos2dx_navmesh_NavMeshAgent_isOnOffMeshLink(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_isOnOffMeshLink : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isOnOffMeshLink();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_isOnOffMeshLink : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_isOnOffMeshLink)

static bool js_cocos2dx_navmesh_NavMeshAgent_setSeparationWeight(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_setSeparationWeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_setSeparationWeight : Error processing arguments");
        cobj->setSeparationWeight(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_setSeparationWeight)

static bool js_cocos2dx_navmesh_NavMeshAgent_pause(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_pause : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->pause();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_pause)

static bool js_cocos2dx_navmesh_NavMeshAgent_setAutoOrientation(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_setAutoOrientation : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_setAutoOrientation : Error processing arguments");
        cobj->setAutoOrientation(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_setAutoOrientation)

static bool js_cocos2dx_navmesh_NavMeshAgent_getHeight(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_getHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getHeight();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_getHeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_getHeight)

static bool js_cocos2dx_navmesh_NavMeshAgent_getMaxSpeed(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_getMaxSpeed : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getMaxSpeed();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_getMaxSpeed : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_getMaxSpeed)

static bool js_cocos2dx_navmesh_NavMeshAgent_getCurrentOffMeshLinkData(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_getCurrentOffMeshLinkData : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::OffMeshLinkData result = cobj->getCurrentOffMeshLinkData();
        #pragma warning NO CONVERSION FROM NATIVE FOR OffMeshLinkData;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_getCurrentOffMeshLinkData : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_getCurrentOffMeshLinkData)

static bool js_cocos2dx_navmesh_NavMeshAgent_getRadius(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_getRadius : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRadius();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_getRadius : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_getRadius)

static bool js_cocos2dx_navmesh_NavMeshAgent_setSyncFlag(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_setSyncFlag : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::NavMeshAgent::NavMeshAgentSyncFlag arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_setSyncFlag : Error processing arguments");
        cobj->setSyncFlag(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_setSyncFlag)

static bool js_cocos2dx_navmesh_NavMeshAgent_getSyncFlag(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_getSyncFlag : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = (unsigned int)cobj->getSyncFlag();
        ok &= uint32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_getSyncFlag : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_getSyncFlag)

static bool js_cocos2dx_navmesh_NavMeshAgent_resume(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_resume : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->resume();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_resume)

static bool js_cocos2dx_navmesh_NavMeshAgent_stop(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_stop : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->stop();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_stop)

static bool js_cocos2dx_navmesh_NavMeshAgent_setMaxAcceleration(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_setMaxAcceleration : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_setMaxAcceleration : Error processing arguments");
        cobj->setMaxAcceleration(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_setMaxAcceleration)

static bool js_cocos2dx_navmesh_NavMeshAgent_setOrientationRefAxes(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_setOrientationRefAxes : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Vec3 arg0;
        ok &= seval_to_Vec3(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_setOrientationRefAxes : Error processing arguments");
        cobj->setOrientationRefAxes(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_setOrientationRefAxes)

static bool js_cocos2dx_navmesh_NavMeshAgent_getMaxAcceleration(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_getMaxAcceleration : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getMaxAcceleration();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_getMaxAcceleration : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_getMaxAcceleration)

static bool js_cocos2dx_navmesh_NavMeshAgent_setHeight(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_setHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_setHeight : Error processing arguments");
        cobj->setHeight(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_setHeight)

static bool js_cocos2dx_navmesh_NavMeshAgent_getObstacleAvoidanceType(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_getObstacleAvoidanceType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        uint8_t result = cobj->getObstacleAvoidanceType();
        ok &= uint8_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_getObstacleAvoidanceType : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_getObstacleAvoidanceType)

static bool js_cocos2dx_navmesh_NavMeshAgent_getVelocity(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_getVelocity : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        cocos2d::Vec3 result = cobj->getVelocity();
        ok &= Vec3_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_getVelocity : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_getVelocity)

static bool js_cocos2dx_navmesh_NavMeshAgent_setRadius(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_setRadius : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_setRadius : Error processing arguments");
        cobj->setRadius(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_setRadius)

static bool js_cocos2dx_navmesh_NavMeshAgent_setObstacleAvoidanceType(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshAgent_setObstacleAvoidanceType : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        uint8_t arg0;
        ok &= seval_to_uint8(args[0], (uint8_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_setObstacleAvoidanceType : Error processing arguments");
        cobj->setObstacleAvoidanceType(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_setObstacleAvoidanceType)

static bool js_cocos2dx_navmesh_NavMeshAgent_getNavMeshAgentComponentName(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cocos2d::NavMeshAgent::getNavMeshAgentComponentName();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_getNavMeshAgentComponentName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_getNavMeshAgentComponentName)

static bool js_cocos2dx_navmesh_NavMeshAgent_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::NavMeshAgentParam arg0;
        #pragma warning NO CONVERSION TO NATIVE FOR NavMeshAgentParam
        ok = false;
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshAgent_create : Error processing arguments");
        auto result = cocos2d::NavMeshAgent::create(arg0);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_NavMeshAgent_class);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshAgent_create)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_NavMeshAgent_finalize)

static bool js_cocos2dx_navmesh_NavMeshAgent_constructor(se::State& s)
{
    cocos2d::NavMeshAgent* cobj = new (std::nothrow) cocos2d::NavMeshAgent();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_navmesh_NavMeshAgent_constructor, __jsb_cocos2d_NavMeshAgent_class, js_cocos2d_NavMeshAgent_finalize)



extern se::Object* __jsb_cocos2d_Component_proto;

static bool js_cocos2d_NavMeshAgent_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::NavMeshAgent)", s.nativeThisObject());
    cocos2d::NavMeshAgent* cobj = (cocos2d::NavMeshAgent*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_NavMeshAgent_finalize)

bool js_register_cocos2dx_navmesh_NavMeshAgent(se::Object* obj)
{
    auto cls = se::Class::create("NavMeshAgent", obj, __jsb_cocos2d_Component_proto, _SE(js_cocos2dx_navmesh_NavMeshAgent_constructor));

    cls->defineFunction("setMaxSpeed", _SE(js_cocos2dx_navmesh_NavMeshAgent_setMaxSpeed));
    cls->defineFunction("syncToNode", _SE(js_cocos2dx_navmesh_NavMeshAgent_syncToNode));
    cls->defineFunction("completeOffMeshLink", _SE(js_cocos2dx_navmesh_NavMeshAgent_completeOffMeshLink));
    cls->defineFunction("getSeparationWeight", _SE(js_cocos2dx_navmesh_NavMeshAgent_getSeparationWeight));
    cls->defineFunction("setAutoTraverseOffMeshLink", _SE(js_cocos2dx_navmesh_NavMeshAgent_setAutoTraverseOffMeshLink));
    cls->defineFunction("getCurrentVelocity", _SE(js_cocos2dx_navmesh_NavMeshAgent_getCurrentVelocity));
    cls->defineFunction("syncToAgent", _SE(js_cocos2dx_navmesh_NavMeshAgent_syncToAgent));
    cls->defineFunction("isOnOffMeshLink", _SE(js_cocos2dx_navmesh_NavMeshAgent_isOnOffMeshLink));
    cls->defineFunction("setSeparationWeight", _SE(js_cocos2dx_navmesh_NavMeshAgent_setSeparationWeight));
    cls->defineFunction("pause", _SE(js_cocos2dx_navmesh_NavMeshAgent_pause));
    cls->defineFunction("setAutoOrientation", _SE(js_cocos2dx_navmesh_NavMeshAgent_setAutoOrientation));
    cls->defineFunction("getHeight", _SE(js_cocos2dx_navmesh_NavMeshAgent_getHeight));
    cls->defineFunction("getMaxSpeed", _SE(js_cocos2dx_navmesh_NavMeshAgent_getMaxSpeed));
    cls->defineFunction("getCurrentOffMeshLinkData", _SE(js_cocos2dx_navmesh_NavMeshAgent_getCurrentOffMeshLinkData));
    cls->defineFunction("getRadius", _SE(js_cocos2dx_navmesh_NavMeshAgent_getRadius));
    cls->defineFunction("setSyncFlag", _SE(js_cocos2dx_navmesh_NavMeshAgent_setSyncFlag));
    cls->defineFunction("getSyncFlag", _SE(js_cocos2dx_navmesh_NavMeshAgent_getSyncFlag));
    cls->defineFunction("resume", _SE(js_cocos2dx_navmesh_NavMeshAgent_resume));
    cls->defineFunction("stop", _SE(js_cocos2dx_navmesh_NavMeshAgent_stop));
    cls->defineFunction("setMaxAcceleration", _SE(js_cocos2dx_navmesh_NavMeshAgent_setMaxAcceleration));
    cls->defineFunction("setOrientationRefAxes", _SE(js_cocos2dx_navmesh_NavMeshAgent_setOrientationRefAxes));
    cls->defineFunction("getMaxAcceleration", _SE(js_cocos2dx_navmesh_NavMeshAgent_getMaxAcceleration));
    cls->defineFunction("setHeight", _SE(js_cocos2dx_navmesh_NavMeshAgent_setHeight));
    cls->defineFunction("getObstacleAvoidanceType", _SE(js_cocos2dx_navmesh_NavMeshAgent_getObstacleAvoidanceType));
    cls->defineFunction("getVelocity", _SE(js_cocos2dx_navmesh_NavMeshAgent_getVelocity));
    cls->defineFunction("setRadius", _SE(js_cocos2dx_navmesh_NavMeshAgent_setRadius));
    cls->defineFunction("setObstacleAvoidanceType", _SE(js_cocos2dx_navmesh_NavMeshAgent_setObstacleAvoidanceType));
    cls->defineStaticFunction("getNavMeshAgentComponentName", _SE(js_cocos2dx_navmesh_NavMeshAgent_getNavMeshAgentComponentName));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_navmesh_NavMeshAgent_create));
    cls->defineFinalizeFunction(_SE(js_cocos2d_NavMeshAgent_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::NavMeshAgent>(cls);

    __jsb_cocos2d_NavMeshAgent_proto = cls->getProto();
    __jsb_cocos2d_NavMeshAgent_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_cocos2d_NavMeshObstacle_proto = nullptr;
se::Class* __jsb_cocos2d_NavMeshObstacle_class = nullptr;

static bool js_cocos2dx_navmesh_NavMeshObstacle_getSyncFlag(se::State& s)
{
    cocos2d::NavMeshObstacle* cobj = (cocos2d::NavMeshObstacle*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshObstacle_getSyncFlag : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        unsigned int result = (unsigned int)cobj->getSyncFlag();
        ok &= uint32_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshObstacle_getSyncFlag : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshObstacle_getSyncFlag)

static bool js_cocos2dx_navmesh_NavMeshObstacle_initWith(se::State& s)
{
    cocos2d::NavMeshObstacle* cobj = (cocos2d::NavMeshObstacle*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshObstacle_initWith : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshObstacle_initWith : Error processing arguments");
        bool result = cobj->initWith(arg0, arg1);
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshObstacle_initWith : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshObstacle_initWith)

static bool js_cocos2dx_navmesh_NavMeshObstacle_syncToObstacle(se::State& s)
{
    cocos2d::NavMeshObstacle* cobj = (cocos2d::NavMeshObstacle*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshObstacle_syncToObstacle : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->syncToObstacle();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshObstacle_syncToObstacle)

static bool js_cocos2dx_navmesh_NavMeshObstacle_syncToNode(se::State& s)
{
    cocos2d::NavMeshObstacle* cobj = (cocos2d::NavMeshObstacle*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshObstacle_syncToNode : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    if (argc == 0) {
        cobj->syncToNode();
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshObstacle_syncToNode)

static bool js_cocos2dx_navmesh_NavMeshObstacle_getHeight(se::State& s)
{
    cocos2d::NavMeshObstacle* cobj = (cocos2d::NavMeshObstacle*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshObstacle_getHeight : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getHeight();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshObstacle_getHeight : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshObstacle_getHeight)

static bool js_cocos2dx_navmesh_NavMeshObstacle_setSyncFlag(se::State& s)
{
    cocos2d::NavMeshObstacle* cobj = (cocos2d::NavMeshObstacle*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshObstacle_setSyncFlag : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::NavMeshObstacle::NavMeshObstacleSyncFlag arg0;
        ok &= seval_to_uint32(args[0], (uint32_t*)&arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshObstacle_setSyncFlag : Error processing arguments");
        cobj->setSyncFlag(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshObstacle_setSyncFlag)

static bool js_cocos2dx_navmesh_NavMeshObstacle_getRadius(se::State& s)
{
    cocos2d::NavMeshObstacle* cobj = (cocos2d::NavMeshObstacle*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMeshObstacle_getRadius : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        float result = cobj->getRadius();
        ok &= float_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshObstacle_getRadius : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshObstacle_getRadius)

static bool js_cocos2dx_navmesh_NavMeshObstacle_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        float arg0 = 0;
        float arg1 = 0;
        ok &= seval_to_float(args[0], &arg0);
        ok &= seval_to_float(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshObstacle_create : Error processing arguments");
        auto result = cocos2d::NavMeshObstacle::create(arg0, arg1);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_NavMeshObstacle_class);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshObstacle_create)

static bool js_cocos2dx_navmesh_NavMeshObstacle_getNavMeshObstacleComponentName(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        const std::string& result = cocos2d::NavMeshObstacle::getNavMeshObstacleComponentName();
        ok &= std_string_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMeshObstacle_getNavMeshObstacleComponentName : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMeshObstacle_getNavMeshObstacleComponentName)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_NavMeshObstacle_finalize)

static bool js_cocos2dx_navmesh_NavMeshObstacle_constructor(se::State& s)
{
    cocos2d::NavMeshObstacle* cobj = new (std::nothrow) cocos2d::NavMeshObstacle();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_navmesh_NavMeshObstacle_constructor, __jsb_cocos2d_NavMeshObstacle_class, js_cocos2d_NavMeshObstacle_finalize)



extern se::Object* __jsb_cocos2d_Component_proto;

static bool js_cocos2d_NavMeshObstacle_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::NavMeshObstacle)", s.nativeThisObject());
    cocos2d::NavMeshObstacle* cobj = (cocos2d::NavMeshObstacle*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_NavMeshObstacle_finalize)

bool js_register_cocos2dx_navmesh_NavMeshObstacle(se::Object* obj)
{
    auto cls = se::Class::create("NavMeshObstacle", obj, __jsb_cocos2d_Component_proto, _SE(js_cocos2dx_navmesh_NavMeshObstacle_constructor));

    cls->defineFunction("getSyncFlag", _SE(js_cocos2dx_navmesh_NavMeshObstacle_getSyncFlag));
    cls->defineFunction("initWith", _SE(js_cocos2dx_navmesh_NavMeshObstacle_initWith));
    cls->defineFunction("syncToObstacle", _SE(js_cocos2dx_navmesh_NavMeshObstacle_syncToObstacle));
    cls->defineFunction("syncToNode", _SE(js_cocos2dx_navmesh_NavMeshObstacle_syncToNode));
    cls->defineFunction("getHeight", _SE(js_cocos2dx_navmesh_NavMeshObstacle_getHeight));
    cls->defineFunction("setSyncFlag", _SE(js_cocos2dx_navmesh_NavMeshObstacle_setSyncFlag));
    cls->defineFunction("getRadius", _SE(js_cocos2dx_navmesh_NavMeshObstacle_getRadius));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_navmesh_NavMeshObstacle_create));
    cls->defineStaticFunction("getNavMeshObstacleComponentName", _SE(js_cocos2dx_navmesh_NavMeshObstacle_getNavMeshObstacleComponentName));
    cls->defineFinalizeFunction(_SE(js_cocos2d_NavMeshObstacle_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::NavMeshObstacle>(cls);

    __jsb_cocos2d_NavMeshObstacle_proto = cls->getProto();
    __jsb_cocos2d_NavMeshObstacle_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

se::Object* __jsb_cocos2d_NavMesh_proto = nullptr;
se::Class* __jsb_cocos2d_NavMesh_class = nullptr;

static bool js_cocos2dx_navmesh_NavMesh_removeNavMeshObstacle(se::State& s)
{
    cocos2d::NavMesh* cobj = (cocos2d::NavMesh*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMesh_removeNavMeshObstacle : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::NavMeshObstacle* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMesh_removeNavMeshObstacle : Error processing arguments");
        cobj->removeNavMeshObstacle(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMesh_removeNavMeshObstacle)

static bool js_cocos2dx_navmesh_NavMesh_removeNavMeshAgent(se::State& s)
{
    cocos2d::NavMesh* cobj = (cocos2d::NavMesh*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMesh_removeNavMeshAgent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::NavMeshAgent* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMesh_removeNavMeshAgent : Error processing arguments");
        cobj->removeNavMeshAgent(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMesh_removeNavMeshAgent)

static bool js_cocos2dx_navmesh_NavMesh_update(se::State& s)
{
    cocos2d::NavMesh* cobj = (cocos2d::NavMesh*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMesh_update : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        float arg0 = 0;
        ok &= seval_to_float(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMesh_update : Error processing arguments");
        cobj->update(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMesh_update)

static bool js_cocos2dx_navmesh_NavMesh_isDebugDrawEnabled(se::State& s)
{
    cocos2d::NavMesh* cobj = (cocos2d::NavMesh*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMesh_isDebugDrawEnabled : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 0) {
        bool result = cobj->isDebugDrawEnabled();
        ok &= boolean_to_seval(result, &s.rval());
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMesh_isDebugDrawEnabled : Error processing arguments");
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 0);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMesh_isDebugDrawEnabled)

static bool js_cocos2dx_navmesh_NavMesh_addNavMeshAgent(se::State& s)
{
    cocos2d::NavMesh* cobj = (cocos2d::NavMesh*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMesh_addNavMeshAgent : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::NavMeshAgent* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMesh_addNavMeshAgent : Error processing arguments");
        cobj->addNavMeshAgent(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMesh_addNavMeshAgent)

static bool js_cocos2dx_navmesh_NavMesh_addNavMeshObstacle(se::State& s)
{
    cocos2d::NavMesh* cobj = (cocos2d::NavMesh*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMesh_addNavMeshObstacle : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::NavMeshObstacle* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMesh_addNavMeshObstacle : Error processing arguments");
        cobj->addNavMeshObstacle(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMesh_addNavMeshObstacle)

static bool js_cocos2dx_navmesh_NavMesh_setDebugDrawEnable(se::State& s)
{
    cocos2d::NavMesh* cobj = (cocos2d::NavMesh*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMesh_setDebugDrawEnable : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        bool arg0;
        ok &= seval_to_boolean(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMesh_setDebugDrawEnable : Error processing arguments");
        cobj->setDebugDrawEnable(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMesh_setDebugDrawEnable)

static bool js_cocos2dx_navmesh_NavMesh_debugDraw(se::State& s)
{
    cocos2d::NavMesh* cobj = (cocos2d::NavMesh*)s.nativeThisObject();
    SE_PRECONDITION2(cobj, false, "js_cocos2dx_navmesh_NavMesh_debugDraw : Invalid Native Object");
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 1) {
        cocos2d::Renderer* arg0 = nullptr;
        ok &= seval_to_native_ptr(args[0], &arg0);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMesh_debugDraw : Error processing arguments");
        cobj->debugDraw(arg0);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMesh_debugDraw)

static bool js_cocos2dx_navmesh_NavMesh_create(se::State& s)
{
    const auto& args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= seval_to_std_string(args[0], &arg0);
        ok &= seval_to_std_string(args[1], &arg1);
        SE_PRECONDITION2(ok, false, "js_cocos2dx_navmesh_NavMesh_create : Error processing arguments");
        auto result = cocos2d::NavMesh::create(arg0, arg1);
        result->retain();
        auto obj = se::Object::createObjectWithClass(__jsb_cocos2d_NavMesh_class);
        obj->setPrivateData(result);
        s.rval().setObject(obj);
        return true;
    }
    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 2);
    return false;
}
SE_BIND_FUNC(js_cocos2dx_navmesh_NavMesh_create)

SE_DECLARE_FINALIZE_FUNC(js_cocos2d_NavMesh_finalize)

static bool js_cocos2dx_navmesh_NavMesh_constructor(se::State& s)
{
    cocos2d::NavMesh* cobj = new (std::nothrow) cocos2d::NavMesh();
    s.thisObject()->setPrivateData(cobj);
    return true;
}
SE_BIND_CTOR(js_cocos2dx_navmesh_NavMesh_constructor, __jsb_cocos2d_NavMesh_class, js_cocos2d_NavMesh_finalize)




static bool js_cocos2d_NavMesh_finalize(se::State& s)
{
    CCLOGINFO("jsbindings: finalizing JS object %p (cocos2d::NavMesh)", s.nativeThisObject());
    cocos2d::NavMesh* cobj = (cocos2d::NavMesh*)s.nativeThisObject();
    cobj->release();
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cocos2d_NavMesh_finalize)

bool js_register_cocos2dx_navmesh_NavMesh(se::Object* obj)
{
    auto cls = se::Class::create("NavMesh", obj, nullptr, _SE(js_cocos2dx_navmesh_NavMesh_constructor));

    cls->defineFunction("removeNavMeshObstacle", _SE(js_cocos2dx_navmesh_NavMesh_removeNavMeshObstacle));
    cls->defineFunction("removeNavMeshAgent", _SE(js_cocos2dx_navmesh_NavMesh_removeNavMeshAgent));
    cls->defineFunction("update", _SE(js_cocos2dx_navmesh_NavMesh_update));
    cls->defineFunction("isDebugDrawEnabled", _SE(js_cocos2dx_navmesh_NavMesh_isDebugDrawEnabled));
    cls->defineFunction("addNavMeshAgent", _SE(js_cocos2dx_navmesh_NavMesh_addNavMeshAgent));
    cls->defineFunction("addNavMeshObstacle", _SE(js_cocos2dx_navmesh_NavMesh_addNavMeshObstacle));
    cls->defineFunction("setDebugDrawEnable", _SE(js_cocos2dx_navmesh_NavMesh_setDebugDrawEnable));
    cls->defineFunction("debugDraw", _SE(js_cocos2dx_navmesh_NavMesh_debugDraw));
    cls->defineStaticFunction("create", _SE(js_cocos2dx_navmesh_NavMesh_create));
    cls->defineFinalizeFunction(_SE(js_cocos2d_NavMesh_finalize));
    cls->install();
    JSBClassType::registerClass<cocos2d::NavMesh>(cls);

    __jsb_cocos2d_NavMesh_proto = cls->getProto();
    __jsb_cocos2d_NavMesh_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_cocos2dx_navmesh(se::Object* obj)
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

    js_register_cocos2dx_navmesh_NavMeshObstacle(ns);
    js_register_cocos2dx_navmesh_NavMeshAgent(ns);
    js_register_cocos2dx_navmesh_NavMesh(ns);
    return true;
}

#endif //#if CC_USE_NAVMESH
