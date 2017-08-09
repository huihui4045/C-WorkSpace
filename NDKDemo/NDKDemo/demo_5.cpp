#include "stdafx.h"

//read 文件读内容
void demo1() {
	char *path = "C:\\Users\\gavin\\Desktop\\file\\friends.txt";

	FILE *fp = fopen(path,"r");

	char buff[500];

	while (fgets(buff,50,fp)) {
		printf("%s",buff);
	}
	fclose(fp);

}
//写文件
void demo2() {

	char *path = "C:\\Users\\gavin\\Desktop\\file\\friends_write.txt";
	FILE *fp = fopen(path,"w");

	if (fp==NULL)
	{
		printf("写文件失败");


	}else{

		char *text = "裴银辉";

		fputs(text,fp);

		fclose(fp);
	}
}

//读写二进制文件

void demo3() {

	char *read_path = "C:\\Users\\gavin\\Desktop\\file\\LogViewPro.exe";

	char *write_path = "C:\\Users\\gavin\\Desktop\\file\\LogViewPro_write.exe";

	FILE *read_fp = fopen(read_path,"rb");

	FILE *write_fp = fopen(write_path,"wb");

	char buff[50];
	int len = 0;
	while ((len=fread(buff,sizeof(char),50,read_fp))!=0) {

		fwrite(buff,sizeof(char),len,write_fp);
	}

	fclose(read_fp);

	fclose(write_fp);



}

void demo4() {
  char *read_path = "C:\\Users\\gavin\\Desktop\\file\\liuyan.png";
  FILE *fp = fopen(read_path, "r");
  if (fp == NULL)
  {
	  printf("结果为NULL");
	  return ;
  }
  else
  {
	  fseek(fp,0,SEEK_END);
	  long filesize = ftell(fp);
	  printf("文件大小：%d\n", filesize);
  }

  

}

//文本文件加密
void encode(char normal_path[],char encode_path[]) {

	FILE *normal_fp = fopen(normal_path,"r");

	FILE *encode_fp = fopen(encode_path, "w");

	int ch;

	while ((ch=fgetc(normal_fp))!=EOF) {

		fputc(ch^7,encode_fp);
	}

	fclose(normal_fp);
	fclose(encode_fp);
}


void decode(char encode_path[], char decode_path[]) {

	FILE *normal_fp = fopen(encode_path, "r");

	FILE *decode_fp = fopen(decode_path, "w");

	int ch;

	while ((ch = fgetc(normal_fp)) != EOF) {

		fputc(ch ^ 7, decode_fp);
	}

	fclose(normal_fp);
	fclose(decode_fp);
}

//文件的加密和解密
void demo5() {

	char *normal_path = "C:\\Users\\gavin\\Desktop\\file\\friends.txt";
	char *encode_path = "C:\\Users\\gavin\\Desktop\\file\\friends_encode.txt";
	char *decode_path = "C:\\Users\\gavin\\Desktop\\file\\friends_decode.txt";

	encode(encode_path, decode_path);


}
void bEncode(char normal_path [],char encode_path[],char *password) {
	FILE *normal_fp = fopen(normal_path, "r");

	FILE *encode_fp = fopen(encode_path, "w");

	int ch;
	int pwd_length = strlen(password);
	int i = 0;

	while ((ch=fgetc(normal_fp))!=EOF) {

		fputc(ch^password[i%pwd_length],encode_fp);

		i = (i++) % 10001;
	}

	fclose(normal_fp);
	fclose(encode_fp);
}

void bDecode(char encode_path[], char decode_path[], char *password) {

	FILE *encode_fp = fopen(encode_path, "r");
    FILE *decode_fp = fopen(decode_path, "w");



	fclose(encode_fp);
	fclose(decode_fp);
}

//二进制加密
void demo6() {

	char *normal_path = "C:\\Users\\gavin\\Desktop\\file\\liuyan.png";
	char *encode_path = "C:\\Users\\gavin\\Desktop\\file\\liuyan_encode.png";

	bEncode(normal_path, encode_path,"huihui");

}



int main() {

	//demo1();

	//demo2();

	//demo3();

	//demo4();

	//demo5();

	demo6();

	system("pause");
	return 0;
}