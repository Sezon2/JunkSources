/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           ��f�̒��ڕ��ёւ������N���X[�f�o�b�O�@�\�֘A��`]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "PixelConverter.h"

namespace AppStdLib{
namespace Utility{

//*************************************************************************************************************************************************************
//���e��@�\�̃f�o�b�O���s�֐�
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//�e��@�\�̃f�o�b�O���s���s�Ȃ��܂��B
//��{�I�ɖ{�N���X�̃f�o�b�O�͂����ōs�Ȃ��Ă��������B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//DebugExec();
//*************************************************************************************************************************************************************
void PixelConverter::DebugExec(){
	
	/*//���V���v���Ȏg�p���@�Ńe�X�g
	UTRGB	TestRGB		= { 0xFA , 0xA1 , 0x10 };
	UTRGB*	TestRGBPtr	= &TestRGB;//�������̏�Ԋm�F�������̂ŁB
	//-------------------------------------------
	PixelConverter::SetConvertMode( tPIXEL::CONVERT::MODE::BGR );//�ϊ����[�h��ݒ�B
	PixelConverter TestConverter = TestRGB;//���̂̍쐬�Ɠ����ɑ�����ăR���o�[�g����e�X�g�B*/

	//���o�C�i���ɕۑ������A�������s�N�Z���f�[�^��vector��ʂ��ĕϊ�����e�X�g
	Binary					TestImgPixelBin;//�e�X�g�p�摜�s�N�Z���f�[�^
	UTRGB*					TestRGBPtr		= NULL;
	vector<PixelConverter>* TestConverter	= NULL;//�ꊇ�ϊ��p��vector�B
	//-------------------------------------------
	TestImgPixelBin.SetEndianType( VType::tENDIAN_TYPE::BIG );
	TestImgPixelBin.Save( 0 , ((short)0x0010) ); TestImgPixelBin.Save( 0 , ((char)0x20) );
	TestImgPixelBin.Save( 0 , ((short)0x0111) ); TestImgPixelBin.Save( 0 , ((char)0x21) );
	TestImgPixelBin.Save( 0 , ((short)0x0212) ); TestImgPixelBin.Save( 0 , ((char)0x22) );
	TestImgPixelBin.Save( 0 , ((short)0x0313) ); TestImgPixelBin.Save( 0 , ((char)0x23) );
	TestImgPixelBin.Save( 0 , ((short)0x0414) ); TestImgPixelBin.Save( 0 , ((char)0x24) );
	TestImgPixelBin.Save( 0 , ((short)0x0515) ); TestImgPixelBin.Save( 0 , ((char)0x25) );
	TestImgPixelBin.Save( 0 , ((short)0x0616) ); TestImgPixelBin.Save( 0 , ((char)0x26) );
	TestImgPixelBin.Save( 0 , ((short)0x0717) ); TestImgPixelBin.Save( 0 , ((char)0x27) );
	TestImgPixelBin.Save( 0 , ((short)0x0818) ); TestImgPixelBin.Save( 0 , ((char)0x28) );
	TestImgPixelBin.Save( 0 , ((short)0x0919) ); TestImgPixelBin.Save( 0 , ((char)0x29) );
	TestImgPixelBin.Save( 0 , ((short)0x0A1A) ); TestImgPixelBin.Save( 0 , ((char)0x2A) );
	TestImgPixelBin.Save( 0 , ((short)0x0B1B) ); TestImgPixelBin.Save( 0 , ((char)0x2B) );
	TestImgPixelBin.Save( 0 , ((short)0x0C1C) ); TestImgPixelBin.Save( 0 , ((char)0x2C) );
	TestImgPixelBin.Save( 0 , ((short)0x0D1D) ); TestImgPixelBin.Save( 0 , ((char)0x2D) );
	TestImgPixelBin.Save( 0 , ((short)0x0E1E) ); TestImgPixelBin.Save( 0 , ((char)0x2E) );
	TestImgPixelBin.Save( 0 , ((short)0x0F1F) ); TestImgPixelBin.Save( 0 , ((char)0x2F) );
	PixelConverter::SetConvertMode( tMODE::BGR );//�ϊ����[�h��ݒ�B
	TestRGBPtr = (UTRGB*)TestImgPixelBin.GetSvBinaryPtr();//�ۑ����Ă���o�C�i���̃|�C���^��UTRGB�̃|�C���^�ɋU������B
	TestConverter = new vector<PixelConverter>( TestRGBPtr , TestRGBPtr + (TestImgPixelBin.GetBinarySizeRef()/sizeof(UTRGB)) );
	delete TestConverter;//�g���I�����vector���폜����B
	TestConverter = NULL;//�폜������NULL�ɂ��Ă����B
	PixelConverter::SetConvertMode( tMODE::RESET );//�g���I������烊�Z�b�g����B

	//���N���X�T�C�Y�m�F
	UINT Size = sizeof(PixelConverter);

}
//*************************************************************************************************************************************************************

}}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
