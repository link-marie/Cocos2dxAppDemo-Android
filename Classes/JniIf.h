/*
 */

#ifndef JNIIF_H_
#define JNIIF_H_

#include "platform/android/jni/JniHelper.h"

/**
 * Specify Java class for JNI
 */
#define	kClassName	"com/linknext/cocos2dx/JniIf"

extern "C" {
	const char* getString( const char* func);
	int getInteger1( const char* className, const char* func);
	int getInteger2( const char* className, const char* func, int i);
	float getFloat( const char* className, const char* func);
	float getFloat2( const char* className, const char* func, int i);
	double getDouble2( const char* className, const char* func, int i);

	extern const char* testString();
	extern int testInt1();
	extern int testInt2( int i);
	extern float testFloat1();
	extern float testFloat2( int i);
	extern double testDouble2( int i);
}


class JniIf {

};

#endif
