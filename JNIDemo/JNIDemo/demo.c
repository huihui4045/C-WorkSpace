#include "stdafx.h"
#include "JNIMain.h"

//静态方法
JNIEXPORT jstring JNICALL Java_JNIMain_getStringFromC
(JNIEnv * env, jclass cls) {

	return (*env)->NewStringUTF(env, "hello jin  JNIHello ");
}
//非静态方法
JNIEXPORT jstring JNICALL Java_JNIMain_getStringFromC2
(JNIEnv * env, jobject obj) {

	return (*env)->NewStringUTF(env, "jni two");
}
//访问非静态域
JNIEXPORT jstring JNICALL Java_JNIMain_accessField
(JNIEnv * env, jobject obj) {
	
	jclass jclz = (*env)->GetObjectClass(env, obj);

	jfieldID jfid = (*env)->GetFieldID(env, jclz, "key", "Ljava/lang/String;");

	jstring jstr = (*env)->GetObjectField(env, obj, jfid);

	char * c_str = (*env)->GetStringUTFChars(env, jstr, NULL);

	char text[30] = "dongNao huihui";
	// 生成新的字符串 dongNao key
	strcat(text, c_str);

	// C -> jni
	jstring new_str = (*env)->NewStringUTF(env, text);

	//修改java中的值

	(*env)->SetObjectField(env,obj,jfid,new_str);
	

	return new_str;

}
//修好静态域
JNIEXPORT void JNICALL Java_JNIMain_accessStaticField
(JNIEnv * env, jobject obj) {

	jclass jclz = (*env)->GetObjectClass(env, obj);

	jfieldID jfid = (*env)->GetStaticFieldID(env, jclz, "count", "I");

	if (jfid==NULL)
	{
		printf("fid is null");
	}else {

		//printf("fid is  not null");

	  jint count=	(*env)->GetStaticIntField(env,jclz,jfid);

	  count=count+10;

	  (*env)->SetStaticIntField(env, jclz, jfid, count);

	}


}