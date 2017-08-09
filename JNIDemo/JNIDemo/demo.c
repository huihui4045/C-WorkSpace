#include "stdafx.h"
#include "JNIMain.h"
#include <Windows.h>

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
//访问非静态方法
JNIEXPORT void JNICALL Java_JNIMain_accessMethod
(JNIEnv * env, jobject jobj) {

	jclass jclz=(*env)->GetObjectClass(env,jobj);

	jmethodID jmid=(*env)->GetMethodID(env, jclz,"getRandomInt","(I)I");

     jint random=(*env)->CallIntMethod(env, jobj, jmid, 400);

	 printf("C random c duankou: %d \n", random);

}

//访问java中的静态方法
JNIEXPORT void JNICALL Java_JNIMain_accessStaticMethod
(JNIEnv * env, jobject obj) {

	jclass jclz = (*env)->GetObjectClass(env, obj);

	jmethodID jmid = (*env)->GetStaticMethodID(env, jclz, "getRandeomUUId", "()Ljava/lang/String;");

	jstring uuid=(*env)->CallStaticObjectMethod(env, jclz,jmid);

	jchar * uuid_c=(*env)->GetStringUTFChars(env,uuid,NULL);

	char filename[400];

	sprintf(filename,"D://aasd%s.txt",uuid_c);

	FILE *fp = fopen(filename,"w");

	fputc("I love huihui ",fp);

	fclose(fp);

	printf("文件写入成功\n");


}

JNIEXPORT jobject JNICALL Java_JNIMain_acceessConstructor
(JNIEnv * env, jobject obj) {

	jclass jclz= (*env)->FindClass(env,"java/util/Date");

	jmethodID jmid=(*env)->GetMethodID(env,jclz,"<init>","()V");

	jobject date_obj=(*env)->NewObject(env,jclz,jmid);

	(*env)->GetMethodID(env,jclz,"getTime","()J");

	jlong time=(*env)->CallLongMethod(env,date_obj,jmid);

	printf("time:%lld \n",time);

	return date_obj;
}

JNIEXPORT jstring JNICALL Java_JNIMain_chineseChars
(JNIEnv * env, jobject obj, jstring str) {


	//char *c_str = (*env)->GetStringChars(env, str, NULL);

	char *c_str = "马蓉与宝宝";

	jclass str_cls = (*env)->FindClass(env, "java/lang/String");
	jmethodID jmid = (*env)->GetMethodID(env, str_cls, "<init>", "([BLjava/lang/String;)V");

	jbyteArray bytes = (*env)->NewByteArray(env, strlen(c_str));

	(*env)->SetByteArrayRegion(env, bytes, 0, strlen(c_str), c_str);
	jstring charsetName = (*env)->NewStringUTF(env, "GBK");

	return (*env)->NewObject(env, str_cls, jmid, bytes, charsetName);

	//jboolean iscp;

 //  char *c_str=	(*env)->GetStringChars(env,str,&iscp);

 //  if (iscp == JNI_TRUE)
 //  {
	//   printf("is copy: JNI_TRUE\n");
 //  }
 //  else if (iscp == JNI_FALSE)
 //  {
	//   printf("is copy: JNI_FALSE\n");
 //  }

 //  int length=(*env)->GetStringLength(env,str);

 //  const jchar * jcstr = (*env)->GetStringChars(env, str, NULL);
 //  if (jcstr == NULL) {
	//   return NULL;
 //  }
 //  //jchar -> char
 //  char * rtn = (char *)malloc(sizeof(char) * 2 * length + 3);
 //  memset(rtn, 0, sizeof(char) * 2 * length + 3);
 // int size = 0;
 //  size = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)jcstr, length, rtn, sizeof(char) * 2 * length + 3, NULL, NULL);
 //  if (size <= 0)
 //  {
 //  printf("size: 0 \n", rtn);
 //  return NULL;
 //  }

 //  printf("string: %s\n", rtn);

 //  if (rtn != NULL) {
	//   free(rtn);
	//   rtn = NULL;
 //  }
 //  (*env)->ReleaseStringChars(env, str, c_str);// JVM 使用。通知JVM c_str 所指的空间可以释放了
 // 



 //  return NULL;
}