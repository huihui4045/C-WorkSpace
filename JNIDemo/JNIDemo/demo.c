#include "stdafx.h"
#include "JNIMain.h"
#include <Windows.h>

//��̬����
JNIEXPORT jstring JNICALL Java_JNIMain_getStringFromC
(JNIEnv * env, jclass cls) {

	return (*env)->NewStringUTF(env, "hello jin  JNIHello ");
}
//�Ǿ�̬����
JNIEXPORT jstring JNICALL Java_JNIMain_getStringFromC2
(JNIEnv * env, jobject obj) {

	return (*env)->NewStringUTF(env, "jni two");
}
//���ʷǾ�̬��
JNIEXPORT jstring JNICALL Java_JNIMain_accessField
(JNIEnv * env, jobject obj) {
	
	jclass jclz = (*env)->GetObjectClass(env, obj);

	jfieldID jfid = (*env)->GetFieldID(env, jclz, "key", "Ljava/lang/String;");

	jstring jstr = (*env)->GetObjectField(env, obj, jfid);

	char * c_str = (*env)->GetStringUTFChars(env, jstr, NULL);

	char text[30] = "dongNao huihui";
	// �����µ��ַ��� dongNao key
	strcat(text, c_str);

	// C -> jni
	jstring new_str = (*env)->NewStringUTF(env, text);

	//�޸�java�е�ֵ

	(*env)->SetObjectField(env,obj,jfid,new_str);
	

	return new_str;

}
//�޺þ�̬��
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
//���ʷǾ�̬����
JNIEXPORT void JNICALL Java_JNIMain_accessMethod
(JNIEnv * env, jobject jobj) {

	jclass jclz=(*env)->GetObjectClass(env,jobj);

	jmethodID jmid=(*env)->GetMethodID(env, jclz,"getRandomInt","(I)I");

     jint random=(*env)->CallIntMethod(env, jobj, jmid, 400);

	 printf("C random c duankou: %d \n", random);

}

//����java�еľ�̬����
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

	printf("�ļ�д��ɹ�\n");


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

	char *c_str = "�����뱦��";

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
 //  (*env)->ReleaseStringChars(env, str, c_str);// JVM ʹ�á�֪ͨJVM c_str ��ָ�Ŀռ�����ͷ���
 // 



 //  return NULL;
}

JNIEXPORT void JNICALL Java_JNIMain_getArray
(JNIEnv * env, jobject jobj, jintArray arr) {

	int compare(jint * a, jint *b);
	jint *element = (*env)->GetIntArrayElements(env, arr, NULL);

	if (element == NULL)
	{

		return;
	}

	int len = (*env)->GetArrayLength(env, arr);

	qsort(element, len, sizeof(jint), compare);
	//�ͷſ��ܵ��ڴ�
	//��JNI �޸ĵ���������д��ԭ�����ڴ�
	(*env)->ReleaseIntArrayElements(env, arr, element, JNI_COMMIT);

}

int compare(jint *a, jint *b) {

	return *a - *b;
}

JNIEXPORT jobjectArray JNICALL Java_JNIMain_initInt2DArray
(JNIEnv * env, jobject jobj, jint jt) {

	
	

}

/*

* Class:     JNIMain
* Method:    initStringArray
* Signature: (I)[Ljava/lang/String;

*/
//���������������͵�����
JNIEXPORT jobjectArray JNICALL Java_JNIMain_initStringArray
(JNIEnv *  env, jobject jobj, jint size) {
	jobjectArray result;

	jclass jclz;
	int i;

	jclz = (*env)->FindClass(env, "java/lang/String");

	if (jclz==NULL) {
		return NULL;
	}
	result = (*env)->NewObjectArray(env,size,jclz,jobj);

	if (result==NULL)
	{
		return NULL;
	}

	for ( i = 0; i < size; i++)
	{
		char * c_str = (char *)malloc(1024);
		//memset�ڴ���亯��  ����������һƬ�ڴ�ռ���г�ʼ��
		memset(c_str,0,256);
		//����sprintf��printf���÷��ϼ���һ����ֻ�Ǵ�ӡ��Ŀ�ĵز�ͬ���ѣ�
		//sprintfǰ�ߴ�ӡ���ַ����У�������ֱ�����������������
		sprintf(c_str,"hello num :%d\n",i);

		jstring  str = (*env)->NewStringUTF(env,c_str);

		if (str==NULL) {
			return NULL;
		}
		(*env)->SetObjectArrayElement(env,result,i,str);

		free(c_str);
		c_str = NULL;
	}


	return result;

}

JNIEXPORT void JNICALL Java_JNIMain_localRef
(JNIEnv * env, jobject jobj) {

	for (int i = 0; i < 5; i++)
	{
		jclass cls = (*env)->FindClass(env,"java/util/Date");

		jmethodID jmid = (*env)->GetMethodID(env,cls,"init","()V");

		jobject obj=(*env)->NewObject(env,cls,jmid);

		//�ͷ�Ӧ��
		(*env)->DeleteLocalRef(env,cls);
		(*env)->DeleteLocalRef(env, obj);


	}
}
//ȫ������
//���߳�ʹ��
//NewGlobalRef �Ǵ���ȫ�����õ�Ψһ����
jstring global_str;
JNIEXPORT void JNICALL Java_JNIMain_createGlobalRef
(JNIEnv * env, jobject jobj) {

   jobject obj=(*env)->NewStringUTF(env,"JNI is intersting");

	global_str = (*env)->NewGlobalRef(env,obj);
}

JNIEXPORT jstring JNICALL Java_JNIMain_getglobalRef
(JNIEnv * env, jobject jobj) {

	return global_str;
}
