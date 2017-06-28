/*
 * Java < - - > C++ interface
 *
 */

#include "cocos2d.h"
#include "JniIf.h"

using namespace cocos2d;

extern "C" {

const char* getString( const char* func) {

	cocos2d::JniMethodInfo methodInfo;
	if( !cocos2d::JniHelper::getStaticMethodInfo( methodInfo, kClassName, func, "()Ljava/lang/String;")) {
		return "";
	}
	// Calling Java class
	jobject objResult = methodInfo.env->CallStaticObjectMethod( methodInfo.classID, methodInfo.methodID);
	// convert jstring to std::string
	std::string ret = cocos2d::JniHelper::jstring2string( (jstring)objResult);
	// release memory
	methodInfo.env->DeleteLocalRef( objResult);
	methodInfo.env->DeleteLocalRef( methodInfo.classID);

	return ret.c_str();
}

int getInteger1( const char* className, const char* func) {
    int ret = 0;
    JniMethodInfo t;
	if (JniHelper::getStaticMethodInfo(t, className, func, "()I")) {
		ret = t.env->CallStaticIntMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);
	}
    return ret;
}
int getInteger2( const char* className, const char* func, int i) {
    int ret = 0;
    JniMethodInfo t;
	if (JniHelper::getStaticMethodInfo(t, className, func, "(I)I")) {
		ret = t.env->CallStaticIntMethod(t.classID, t.methodID, i);
		t.env->DeleteLocalRef(t.classID);
	}
    return ret;
}

float getFloat1( const char* className, const char* func) {
    float ret = 0.0;
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, className, func, "()F")) {
        ret = t.env->CallStaticFloatMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

float getFloat2( const char* className, const char* func, int i) {
    float ret = 0.0;
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, className, func, "(I)F")) {
        ret = t.env->CallStaticFloatMethod(t.classID, t.methodID, i);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}

double getDouble2( const char* className, const char* func, int i) {
    double ret = 0.0;
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, className, func, "(I)D")) {
        ret = t.env->CallStaticDoubleMethod(t.classID, t.methodID, i);
        t.env->DeleteLocalRef(t.classID);
    }
    return ret;
}


const char* testString(){
    const char* funcName = "testString";
    const char* funcRet = getString( funcName);
    return funcRet;
}

int testInt1(){
    const char* funcName = "testInt1";
    int funcRet = getInteger1( kClassName, funcName);
    return funcRet;
}

int testInt2( int i){
    const char* funcName = "testInt2";
    int funcRet = getInteger2( kClassName, funcName, i);
    return funcRet;
}

float testFloat1(){
    const char* funcName = "testFloat1";
    float funcRet = getFloat1( kClassName, funcName);
    return funcRet;
}

float testFloat2( int i){
    const char* funcName = "testFloat2";
    float funcRet = getFloat2( kClassName, funcName, i);
    return funcRet;
}

double testDouble2( int i){
    const char* funcName = "testDouble2";
    float funcRet = getDouble2( kClassName, funcName, i);
    return funcRet;
}


}
