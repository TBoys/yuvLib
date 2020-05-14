#include <stdio.h>
#include <stdlib.h>
#include <string.h>

__inline unsigned int Trunc(unsigned int value)
{ return ((int) value) < 0 ? 0 : ((int) value) > 0xff00 ? 0xff00 : value; }


inline void YUV2RGB1 (unsigned char y, unsigned char u, unsigned char v, unsigned char *r, unsigned char *g, unsigned char *b)
{
	*r = Trunc(256*y + 360*v - 360*128 + 128) >> 8;
	*g = Trunc(256*y - 63*u  + 63*128 - 184*v + 184*128 +128 ) >> 8;
	*b = Trunc(256*y + 455*u - 455*128 + 128) >> 8;
}

extern "C" int YUV422toRGB(unsigned char **dst, int width, int height, const unsigned char *src)
{
	//��������
	int x = 0;
	int y = 0;
	int widthRGB;
	int imageSize = width * height;
	int frameSize = imageSize * 2;

	const unsigned char* pY;
	const unsigned char* pU;
	const unsigned char* pV;
	unsigned char  r, g, b;

	unsigned char* pRGB;


	//����ռ�
	x		 = width * 3 % 4;
	widthRGB = (width * 3 + (x? 4-x: 0));
	*dst = (unsigned char *)malloc(widthRGB * height);
	//rgb  = (unsigned char *)malloc((width * 3 + x? 4-x: 0) * height);

	//ת��ָ��֡  ����㲻�Ǵ����ļ� ��Ҫ������
	pY = src;						//y������ַ
	pU = pY + imageSize;			//u������ַ
	pV = pU + (imageSize >> 1);		//v������ַ

	pRGB = *dst;

	for(y=0; y < height; y++)
	{
		pRGB = *dst + widthRGB * y;
		for(x=0; x < width; x++)
		{
			YUV2RGB1(pY[y*(width)+x], pU[(y/2)*(width)+x/2], pV[(y/2)*(width)+x/2], 
				&r, &g, &b);
			*(pRGB + x*3) = b;
			*(pRGB + x*3 + 1) = g;
			*(pRGB + x*3 + 2) = r;
		}
	}

	return 0;
}

extern "C" int YUV420toRGB(unsigned char **dst, int width, int height, const unsigned char *src)
{
	//��������
	int x = 0;
	int y = 0;
	int widthRGB;
	int imageSize = width * height;
	int frameSize = imageSize + (imageSize >> 1);

	const unsigned char* pY;
	const unsigned char* pU;
	const unsigned char* pV;
	unsigned char  r, g, b;

	unsigned char* pRGB;


	//����ռ�
	x		 = width * 3 % 4;
	widthRGB = (width * 3 + (x? 4-x: 0));
	*dst = (unsigned char *)malloc(widthRGB * height);
	//rgb  = (unsigned char *)malloc((width * 3 + x? 4-x: 0) * height);


	//ת��ָ��֡  ����㲻�Ǵ����ļ� ��Ҫ������
	pY = src;						//y������ַ
	pU = pY + imageSize;			//u������ַ
	pV = pU + (imageSize >> 2);		//v������ַ

	pRGB = *dst;

	for(y=0; y < height; y++)
	{
		pRGB = *dst + widthRGB * y;
		for(x=0; x < width; x++)
		{
			YUV2RGB1(pY[y*(width)+x], pU[(y/2)*(width/2)+x/2], pV[(y/2)*(width/2)+x/2], 
				&r, &g, &b);
			*(pRGB + x*3) = b;
			*(pRGB + x*3 + 1) = g;
			*(pRGB + x*3 + 2) = r;
		}
	}

	return 0;
}

extern "C" int YUV420SPtoARGB(unsigned char **dst, int width, int height, const unsigned char *src)
{
	//��������
	int x = 0;
	int y = 0;
	int widthRGB;
	int imageSize = width * height;
	int frameSize = imageSize + (imageSize >> 1);

	const unsigned char* pY;
	const unsigned char* pUV;
	const unsigned char* pV;
	unsigned char  r, g, b;

	unsigned char* pRGB;


	//����ռ�
	x		 = width * 4 % 4;
	widthRGB = (width * 4 + (x? 4-x: 0));
	//*dst = (unsigned char *)malloc(widthRGB * height);//���ⲿʵ��
	//rgb  = (unsigned char *)malloc((width * 3 + x? 4-x: 0) * height);


	//ת��ָ��֡  ����㲻�Ǵ����ļ� ��Ҫ������
	pY = src;						//y������ַ
	pUV = pY + imageSize;			//u������ַ

	pRGB = *dst;

	for(y=0; y < height; y++)
	{
		pRGB = *dst + widthRGB * y;
		for(x=0; x < width; x++)
		{
			YUV2RGB1(pY[y*(width)+x], pUV[((y/2)*(width/2)+x/2)*2], pUV[((y/2)*(width/2)+x/2)*2+1], 
				&r, &g, &b);
			*(pRGB + x*4) = b;
			*(pRGB + x*4 + 1) = g;
			*(pRGB + x*4 + 2) = r;
			*(pRGB + x*4 + 3) = 255;
		}
	}

	return 0;
}


extern "C" int YUV420SPtoRGBA(unsigned char **dst, int width, int height, const unsigned char *src)
{
	//��������
	int x = 0;
	int y = 0;
	int widthRGB;
	int imageSize = width * height;
	int frameSize = imageSize + (imageSize >> 1);

	const unsigned char* pY;
	const unsigned char* pUV;
	const unsigned char* pV;
	unsigned char  r, g, b;

	unsigned char* pRGB;


	//����ռ�
	x		 = width * 4 % 4;
	widthRGB = (width * 4 + (x? 4-x: 0));
	//*dst = (unsigned char *)malloc(widthRGB * height);//���ⲿʵ��
	//rgb  = (unsigned char *)malloc((width * 3 + x? 4-x: 0) * height);


	//ת��ָ��֡  ����㲻�Ǵ����ļ� ��Ҫ������
	pY = src;						//y������ַ
	pUV = pY + imageSize;			//u������ַ

	pRGB = *dst;

	for(y=0; y < height; y++)
	{
		pRGB = *dst + widthRGB * y;
		for(x=0; x < width; x++)
		{
			YUV2RGB1(pY[y*(width)+x], pUV[((y/2)*(width/2)+x/2)*2], pUV[((y/2)*(width/2)+x/2)*2+1],
					 &r, &g, &b);
			*(pRGB + x*4) = 255;
			*(pRGB + x*4 + 1) = b;
			*(pRGB + x*4 + 2) = g;
			*(pRGB + x*4 + 3) = r;
		}
	}

	return 0;
}


extern "C" int YUV420SPtoRGB(unsigned char **dst, int width, int height, const unsigned char *src)
{
	//��������
	int x = 0;
	int y = 0;
	int widthRGB;
	int imageSize = width * height;
	int frameSize = imageSize + (imageSize >> 1);

	const unsigned char* pY;
	const unsigned char* pUV;
	const unsigned char* pV;
	unsigned char  r, g, b;

	unsigned char* pRGB;


	//����ռ�
	x		 = 0;//width * 3 % 4;
	widthRGB = (width * 3 + (x? 4-x: 0));
	//*dst = (unsigned char *)malloc(widthRGB * height);//���ⲿʵ��
	//rgb  = (unsigned char *)malloc((width * 3 + x? 4-x: 0) * height);


	//ת��ָ��֡  ����㲻�Ǵ����ļ� ��Ҫ������
	pY = src;						//y������ַ
	pUV = pY + imageSize;			//u������ַ

	pRGB = *dst;

	for(y=0; y < height; y++)
	{
		pRGB = *dst + widthRGB * y;
		for(x=0; x < width; x++)
		{
			YUV2RGB1(pY[y*(width)+x], pUV[((y/2)*(width/2)+x/2)*2], pUV[((y/2)*(width/2)+x/2)*2+1],
					 &r, &g, &b);
			*(pRGB + x*3) = b;
			*(pRGB + x*3 + 1) = g;
			*(pRGB + x*3 + 2) = r;
		}
	}

	return 0;
}

extern "C" int YUV420SPtoBGR(unsigned char **dst, int width, int height, const unsigned char *src)
{
	//��������
	int x = 0;
	int y = 0;
	int widthRGB;
	int imageSize = width * height;
	int frameSize = imageSize + (imageSize >> 1);

	const unsigned char* pY;
	const unsigned char* pUV;
	const unsigned char* pV;
	unsigned char  r, g, b;

	unsigned char* pRGB;


	//����ռ�
	x		 = 0;//width * 3 % 4;
	widthRGB = (width * 3 + (x? 4-x: 0));
	//*dst = (unsigned char *)malloc(widthRGB * height);//���ⲿʵ��
	//rgb  = (unsigned char *)malloc((width * 3 + x? 4-x: 0) * height);


	//ת��ָ��֡  ����㲻�Ǵ����ļ� ��Ҫ������
	pY = src;						//y������ַ
	pUV = pY + imageSize;			//u������ַ

	pRGB = *dst;

	for(y=0; y < height; y++)
	{
		pRGB = *dst + widthRGB * y;
		for(x=0; x < width; x++)
		{
			YUV2RGB1(pY[y*(width)+x], pUV[((y/2)*(width/2)+x/2)*2], pUV[((y/2)*(width/2)+x/2)*2+1], 
				&r, &g, &b);
			*(pRGB + x*3) = r;
			*(pRGB + x*3 + 1) = g;
			*(pRGB + x*3 + 2) = b;
		}
	}

	return 0;
}

extern "C" int UYVYtoRGB(unsigned char **dst, int width, int height, const unsigned char *src)
{
	//��������
	int x = 0;
	int y = 0;
	int widthRGB;
	int imageSize = width * height;
	int frameSize = imageSize + (imageSize >> 1);

	const unsigned char* pUYVY;
	unsigned char* pRGB;


	//����ռ�
	x		 = width * 3 % 4;
	widthRGB = (width * 3 + (x? 4-x: 0));
	*dst = (unsigned char *)malloc(widthRGB * height);
	//rgb  = (unsigned char *)malloc((width * 3 + x? 4-x: 0) * height);


	//ת��ָ��֡  ����㲻�Ǵ����ļ� ��Ҫ������
	pUYVY = src;						//y������ַ
	pRGB = *dst;

	for(y=0; y < height; y++)
	{
		pRGB = *dst + widthRGB * y;
		for(x=0; x < width; x+=2)
		{
			YUV2RGB1(pUYVY[1], pUYVY[0], pUYVY[2], pRGB+2, pRGB+1, pRGB);
			pRGB+=3;

			YUV2RGB1(pUYVY[3], pUYVY[0], pUYVY[2], pRGB+2, pRGB+1, pRGB);
			pRGB+=3;

			pUYVY+=4;	
		}
	}

	return 0;
}

void swap_byte(unsigned char &x, unsigned char &y)
{
	unsigned char temp = x;
	x = y;
	y = temp;
}
	
void swap_short(unsigned short &x, unsigned short &y)
{
	unsigned short temp = x;
	x = y;
	y = temp;
}

extern "C" int YUV420SPFlip(unsigned char *src, int width, int height )
{
	//��������
	int x = 0;
	int imageSize = width * height;
	unsigned char* pY;
	unsigned short* pUV;

	//ת��ָ��֡ ����㲻�Ǵ����ļ� ��Ҫ������
	pY = src;								//y������ַ
	pUV = (unsigned short*)(pY + imageSize);//u������ַ

	for(x=0; x < imageSize/2; x++)
	{
		swap_byte(pY[x], pY[imageSize-1-x]);  //Byte
	}

	for(x=0; x < imageSize/4/2; x++)
	{
		swap_short(pUV[x], pUV[imageSize/4-1-x]) ; //Short
	}

	return 0;
	
}

extern "C" int YUV420SPMirror(unsigned char *src, int width, int height, int angle, int isMirror )
{
	//��������
	int x = 0;
	int hWidth=width/2;
	int hHeight=height/2;
	int imageSize = width * height;
	unsigned char* pY;
	unsigned short* pUV;

	pY = src;								//y������ַ
	pUV = (unsigned short*)(pY + imageSize);//u������ַ

	unsigned char* tempBuff = (unsigned char*)malloc(imageSize);
	for (int i=0; i<width; i++)
	{
		for(int j=0; j<height; j++)
		{
			if( 90 == angle && 0 == isMirror)
				tempBuff[i*height+j]=pY[(height-1-j)*width+(width-1-i)];
			else if( 90 == angle && 1 == isMirror)
				tempBuff[i*height+(height-1-j)]=pY[(height-1-j)*width+(width-1-i)];
		    else if( 270 == angle && 0 == isMirror)
                tempBuff[i*height+j]=pY[(height-1-j)*width+i];
            else if( 270 == angle && 1 == isMirror)
                tempBuff[i*height+(height-1-j)]=pY[(height-1-j)*width+i];

		}
	}
	memcpy(pY, tempBuff, imageSize);

	unsigned short* tempUV = (unsigned short*)tempBuff;

	for (int i=0; i<hWidth; i++)
	{
		for(int j=0; j<hHeight; j++)
		{
			if( 90 == angle && 0 == isMirror)
				tempUV[i*hHeight+j]=pUV[(hHeight-1-j)*hWidth+(hWidth-1-i)];
			else if( 90 == angle && 1 == isMirror)
				tempUV[i*hHeight+(hHeight-1-j)]=pUV[(hHeight-1-j)*hWidth+(hWidth-1-i)];
			else if( 270 == angle && 0 == isMirror)
                tempUV[i*hHeight+j]=pUV[(hHeight-1-j)*hWidth+i];
            else if( 270 == angle && 1 == isMirror)
                tempUV[i*hHeight+(hHeight-1-j)]=pUV[(hHeight-1-j)*hWidth+i];
		}
	}
	memcpy(pUV, tempUV, imageSize/2);

	free(tempUV);
	return 0;
	
}

//YV12 -> I420
extern "C" int Yv12ToI420(unsigned char* pYv12, unsigned char* pI420, int width, int height)
{
    if(pYv12 == NULL || pI420 == NULL){
        return 1;
    }

    int frameSize = width * height;
    if(frameSize <= 0){
        return 2;
    }

    //拷贝Y分量
    memcpy(pI420,pYv12,frameSize);
    //拷贝U分量
    memcpy(pI420+frameSize,pYv12+frameSize*5/4,frameSize/4);
    //拷贝V分量
    memcpy(pI420+frameSize*5/4,pYv12+frameSize,frameSize/4);

    return 0;
}

//I420 -> YV12
extern "C" int I420ToYv12(unsigned char* pI420, unsigned char* pYv12, int width, int height)
{
    if(pI420 == NULL || pYv12 == NULL){
        return 1;
    }

    int frameSize = width * height;
    if(frameSize <= 0){
        return 2;
    }

    //拷贝Y分量
    memcpy(pYv12,pI420,frameSize);
    //拷贝V分量
    memcpy(pYv12+frameSize,pI420+frameSize*5/4,frameSize/4);
    //拷贝U分量
    memcpy(pYv12+frameSize*5/4,pI420+frameSize,frameSize/4);
    return 0;
}

//NV21 -> I420
extern "C" int Nv21ToI420(unsigned char* pNv21,unsigned char* pI420,int width,int height)
{
	if(pNv21 == NULL || pI420 == NULL){
		return 1;
	}

	int frameSize = width * height;
	if(frameSize <= 0){
		return 2;
	}

	int i = 0;
	//拷贝Y分量
	memcpy(pI420,pNv21,frameSize);

	for (i = 0; i < frameSize / 2; i += 2) {
		//U分量
		pI420[frameSize + i/2] = pNv21[frameSize + i + 1];
		//V分量
		pI420[frameSize + i/2 + frameSize / 4] = pNv21[frameSize + i];
	}

	return 0;
}

//I420 -> NV21
extern "C" int I420ToNv21(unsigned char* pI420,unsigned char* pNv21,int width,int height)
{
	if(pI420 == NULL || pNv21 == NULL){
		return 1;
	}

	int frameSize = width * height;
	if(frameSize <= 0){
		return 2;
	}

	int i = 0;
	//拷贝Y分量
	memcpy(pNv21,pI420,frameSize);

	for (i = 0; i < frameSize / 2; i += 2) {
		//V分量
		pNv21[frameSize + i] = pI420[frameSize + frameSize/4 + i/2];
		//U分量
		pNv21[frameSize + i + 1] = pI420[frameSize + i/2];
	}
	return 0;
}

//NV21 -> Yv12
extern "C" int Nv21ToYv12(unsigned char* pNv21,unsigned char* pYv12,int width,int height)
{
	if(pNv21 == NULL || pYv12 == NULL){
		return 1;
	}

	int frameSize = width * height;
	if(frameSize <= 0){
		return 2;
	}

	int i = 0;
	//拷贝Y分量
	memcpy(pYv12,pNv21,frameSize);

	for (i = 0; i < frameSize / 2; i += 2) {
		//V分量
		pYv12[frameSize + i/2] = pNv21[frameSize + i];//pNv21[frameSize + i + 1];
		//U分量
		pYv12[frameSize + i/2 + frameSize / 4] = pNv21[frameSize + i + 1];
	}
	return 0;
}

//YV12 -> NV21
extern "C" int Yv12ToNv21(unsigned char* pYv12,unsigned char* pNv21,int width,int height)
{
	if(pYv12 == NULL || pNv21 == NULL){
		return 1;
	}

	int frameSize = width * height;
	if(frameSize <= 0){
		return 2;
	}

	int i = 0;
	//拷贝Y分量
	memcpy(pNv21,pYv12,frameSize);

	for (i = 0; i < frameSize / 2; i += 2) {
		//V分量
		pNv21[frameSize + i] = pYv12[frameSize + i/2];
		//U分量
		pNv21[frameSize + i + 1] = pYv12[frameSize + frameSize/4 + i/2];
	}
	return 0;
}

//NV21 -> NV12
extern "C" int Nv21ToNv12(unsigned char* pNv21,unsigned char* pNv12,int width,int height)
{
	if(pNv21 == NULL || pNv12 == NULL){
		return 1;
	}

	int frameSize = width * height;
	if(frameSize <= 0){
		return 2;
	}

	//拷贝Y分量
	memcpy(pNv12,pNv21,frameSize);

	int i = 0;
	for (i = 0; i < frameSize / 4; i++) {
		pNv12[frameSize + i * 2] = pNv21[frameSize + i * 2 + 1]; //U
		pNv12[frameSize + i * 2 + 1] = pNv21[frameSize + i * 2]; //V
	}
	return 0;
}

//NV12 -> NV21
extern "C" int Nv12ToNv21(unsigned char* pNv12,unsigned char* pNv21,int width,int height)
{
	if(pNv12 == NULL || pNv21 == NULL){
		return 1;
	}

	int frameSize = width * height;
	if(frameSize <= 0){
		return 2;
	}

	//拷贝Y分量
	memcpy(pNv21,pNv12,frameSize);

	int i = 0;
	for (i = 0; i < frameSize / 4; i++) {
		pNv21[frameSize + i * 2] = pNv12[frameSize + i * 2 + 1]; //V
		pNv21[frameSize + i * 2 + 1] = pNv12[frameSize + i * 2]; //U
	}
	return 0;
}










