/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           ��f�̒��ڕ��ёւ������N���X[��{�@�\�֘A��`]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "PixelConverter.h"

namespace AppStdLib{
namespace Utility{

//*************************************************************************************************************************************************************
//��RGB�̃s�N�Z���F��ConvertMode�Ŏw�肵�����т̃s�N�Z���F�ɕϊ�����SaveBinary�Ɋi�[����֐�
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//RGB�̃s�N�Z���F��ConvertMode�Ŏw�肵�����т̃s�N�Z���F�ɕϊ�����SaveBinary�Ɋi�[���܂��B
//�R���o�[�g���ꂽRGB��f�l�͒ǉ�����`�Ŋi�[����܂��̂ŁA���ӂ��Ă��������B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//PixelConverter::ConvertPixel( <const UTRGB &$InitVar> );
//<const UTRGB &$InitVar>�F�ϊ����̃s�N�Z���F�\���̂��w�肵�܂��B
//*************************************************************************************************************************************************************
void PixelConverter::ConvertPixel( const UTRGB &$InitVar ){
	
	UTXRGB15 fXRGB15Conv = {0,0,0,0};//XRGB15�s�N�Z���J���[�\���̕ϊ��p

	switch ( ConvertMode ) {
		
		case tMODE::RGB:
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			break;
		
		case tMODE::RGBA:
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::ARGB:
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//���ߓx�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			break;
		
		case tMODE::BGR:
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			break;
		
		case tMODE::BGRA:
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::XRGB:
			SaveBinary.Save( 0 , tX_RESERVED_VAL	);//�\��̈�̗v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			break;
		
		case tMODE::XRGB15:
			fXRGB15Conv.Reserved = 0;				//�\��̈�̗v�f��ݒ�
			fXRGB15Conv.Red		 = $InitVar.Red;	//�ԗv�f��ݒ�
			fXRGB15Conv.Green	 = $InitVar.Green;	//�Ηv�f��ݒ�
			fXRGB15Conv.Blue	 = $InitVar.Blue;	//�v�f��ݒ�
			SaveBinary.Save( 0 , *((UINT16*)(&fXRGB15Conv)) );//�\��̈�Ɛԗΐv�f��ۑ�
			break;
		
	}

}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//��RGBA�̃s�N�Z���F��ConvertMode�Ŏw�肵�����т̃s�N�Z���F�ɕϊ�����SaveBinary�Ɋi�[����֐�
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//RGBA�̃s�N�Z���F��ConvertMode�Ŏw�肵�����т̃s�N�Z���F�ɕϊ�����SaveBinary�Ɋi�[���܂��B
//�R���o�[�g���ꂽRGBA��f�l�͒ǉ�����`�Ŋi�[����܂��̂ŁA���ӂ��Ă��������B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//PixelConverter::ConvertPixel( <const UTRGBA &$InitVar> );
//<const UTRGBA &$InitVar>�F�ϊ����̃s�N�Z���F�\���̂��w�肵�܂��B
//*************************************************************************************************************************************************************
void PixelConverter::ConvertPixel( const UTRGBA &$InitVar ){
	
	UTXRGB15 fXRGB15Conv = {0,0,0,0};//XRGB15�s�N�Z���J���[�\���̕ϊ��p

	switch ( ConvertMode ) {
		
		case tMODE::RGB:
			SaveBinary	 .Save( 0 , $InitVar.Red	);//�ԗv�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Green	);//�Ηv�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//�v�f��ۑ�
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::RGBA:
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Alpha		);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::ARGB:
			SaveBinary.Save( 0 , $InitVar.Alpha		);//���ߓx�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			break;
		
		case tMODE::BGR:
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//�v�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Green	);//�Ηv�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Red	);//�ԗv�f��ۑ�
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::BGRA:
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Alpha		);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::XRGB:
			SaveBinary	 .Save( 0 , tX_RESERVED_VAL	);//�\��̈�̗v�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Red	);//�ԗv�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Green	);//�Ηv�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//�v�f��ۑ�
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::XRGB15:
			fXRGB15Conv.Reserved = 0;				//�\��̈�̗v�f��ݒ�
			fXRGB15Conv.Red		 = $InitVar.Red;	//�ԗv�f��ݒ�
			fXRGB15Conv.Green	 = $InitVar.Green;	//�Ηv�f��ݒ�
			fXRGB15Conv.Blue	 = $InitVar.Blue;	//�v�f��ݒ�
			SaveBinary	 .Save( 0 , *((UINT16*)(&fXRGB15Conv))	);//�\��̈�Ɛԗΐv�f��ۑ�
			DestAlphaData.Save( 0 , $InitVar.Alpha				);//���ߓx�v�f��ۑ�
			break;
		
	}

}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//��ARGB�̃s�N�Z���F��ConvertMode�Ŏw�肵�����т̃s�N�Z���F�ɕϊ�����SaveBinary�Ɋi�[����֐�
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//ARGB�̃s�N�Z���F��ConvertMode�Ŏw�肵�����т̃s�N�Z���F�ɕϊ�����SaveBinary�Ɋi�[���܂��B
//�R���o�[�g���ꂽARGB��f�l�͒ǉ�����`�Ŋi�[����܂��̂ŁA���ӂ��Ă��������B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//PixelConverter::ConvertPixel( <const UTARGB &$InitVar> );
//<const UTARGB &$InitVar>�F�ϊ����̃s�N�Z���F�\���̂��w�肵�܂��B
//*************************************************************************************************************************************************************
void PixelConverter::ConvertPixel( const UTARGB &$InitVar ){
	
	UTXRGB15 fXRGB15Conv = {0,0,0,0};//XRGB15�s�N�Z���J���[�\���̕ϊ��p

	switch ( ConvertMode ) {
		
		case tMODE::RGB:
			SaveBinary	 .Save( 0 , $InitVar.Red	);//�ԗv�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Green	);//�Ηv�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//�v�f��ۑ�
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::RGBA:
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Alpha		);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::ARGB:
			SaveBinary.Save( 0 , $InitVar.Alpha		);//���ߓx�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			break;
		
		case tMODE::BGR:
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//�v�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Green	);//�Ηv�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Red	);//�ԗv�f��ۑ�
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::BGRA:
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Alpha		);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::XRGB:
			SaveBinary	 .Save( 0 , tX_RESERVED_VAL	);//�\��̈�̗v�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Red	);//�ԗv�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Green	);//�Ηv�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//�v�f��ۑ�
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::XRGB15:
			fXRGB15Conv.Reserved = 0;				//�\��̈�̗v�f��ݒ�
			fXRGB15Conv.Red		 = $InitVar.Red;	//�ԗv�f��ݒ�
			fXRGB15Conv.Green	 = $InitVar.Green;	//�Ηv�f��ݒ�
			fXRGB15Conv.Blue	 = $InitVar.Blue;	//�v�f��ݒ�
			SaveBinary	 .Save( 0 , *((UINT16*)(&fXRGB15Conv))	);//�\��̈�Ɛԗΐv�f��ۑ�
			DestAlphaData.Save( 0 , $InitVar.Alpha				);//���ߓx�v�f��ۑ�
			break;
		
	}

}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//��BGR�̃s�N�Z���F��ConvertMode�Ŏw�肵�����т̃s�N�Z���F�ɕϊ�����SaveBinary�Ɋi�[����֐�
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//BGR�̃s�N�Z���F��ConvertMode�Ŏw�肵�����т̃s�N�Z���F�ɕϊ�����SaveBinary�Ɋi�[���܂��B
//�R���o�[�g���ꂽBGR��f�l�͒ǉ�����`�Ŋi�[����܂��̂ŁA���ӂ��Ă��������B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//PixelConverter::ConvertPixel( <const UTBGR &$InitVar> );
//<const UTBGR &$InitVar>�F�ϊ����̃s�N�Z���F�\���̂��w�肵�܂��B
//*************************************************************************************************************************************************************
void PixelConverter::ConvertPixel( const UTBGR &$InitVar ){
	
	UTXRGB15 fXRGB15Conv = {0,0,0,0};//XRGB15�s�N�Z���J���[�\���̕ϊ��p

	switch ( ConvertMode ) {
		
		case tMODE::RGB:
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			break;
		
		case tMODE::RGBA:
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::ARGB:
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//���ߓx�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			break;
		
		case tMODE::BGR:
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			break;
		
		case tMODE::BGRA:
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::XRGB:
			SaveBinary.Save( 0 , tX_RESERVED_VAL	);//�\��̈�̗v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			break;
		
		case tMODE::XRGB15:
			fXRGB15Conv.Reserved = 0;				//�\��̈�̗v�f��ݒ�
			fXRGB15Conv.Red		 = $InitVar.Red;	//�ԗv�f��ݒ�
			fXRGB15Conv.Green	 = $InitVar.Green;	//�Ηv�f��ݒ�
			fXRGB15Conv.Blue	 = $InitVar.Blue;	//�v�f��ݒ�
			SaveBinary.Save( 0 , *((UINT16*)(&fXRGB15Conv)) );//�\��̈�Ɛԗΐv�f��ۑ�
			break;
		
	}

}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//��BGRA�̃s�N�Z���F��ConvertMode�Ŏw�肵�����т̃s�N�Z���F�ɕϊ�����SaveBinary�Ɋi�[����֐�
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//BGRA�̃s�N�Z���F��ConvertMode�Ŏw�肵�����т̃s�N�Z���F�ɕϊ�����SaveBinary�Ɋi�[���܂��B
//�R���o�[�g���ꂽBGRA��f�l�͒ǉ�����`�Ŋi�[����܂��̂ŁA���ӂ��Ă��������B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//PixelConverter::ConvertPixel( <const UTBGRA &$InitVar> );
//<const UTBGRA &$InitVar>�F�ϊ����̃s�N�Z���F�\���̂��w�肵�܂��B
//*************************************************************************************************************************************************************
void PixelConverter::ConvertPixel( const UTBGRA	&$InitVar ){
	
	UTXRGB15 fXRGB15Conv = {0,0,0,0};//XRGB15�s�N�Z���J���[�\���̕ϊ��p

	switch ( ConvertMode ) {
		
		case tMODE::RGB:
			SaveBinary	 .Save( 0 , $InitVar.Red	);//�ԗv�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Green	);//�Ηv�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//�v�f��ۑ�
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::RGBA:
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Alpha		);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::ARGB:
			SaveBinary.Save( 0 , $InitVar.Alpha		);//���ߓx�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			break;
		
		case tMODE::BGR:
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//�v�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Green	);//�Ηv�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Red	);//�ԗv�f��ۑ�
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::BGRA:
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Alpha		);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::XRGB:
			SaveBinary	 .Save( 0 , tX_RESERVED_VAL	);//�\��̈�̗v�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Red	);//�ԗv�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Green	);//�Ηv�f��ۑ�
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//�v�f��ۑ�
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::XRGB15:
			fXRGB15Conv.Reserved = 0;				//�\��̈�̗v�f��ݒ�
			fXRGB15Conv.Red		 = $InitVar.Red;	//�ԗv�f��ݒ�
			fXRGB15Conv.Green	 = $InitVar.Green;	//�Ηv�f��ݒ�
			fXRGB15Conv.Blue	 = $InitVar.Blue;	//�v�f��ݒ�
			SaveBinary	 .Save( 0 , *((UINT16*)(&fXRGB15Conv))	);//�\��̈�Ɛԗΐv�f��ۑ�
			DestAlphaData.Save( 0 , $InitVar.Alpha				);//���ߓx�v�f��ۑ�
			break;
		
	}

}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//��XRGB�̃s�N�Z���F��ConvertMode�Ŏw�肵�����т̃s�N�Z���F�ɕϊ�����SaveBinary�Ɋi�[����֐�
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//XRGB�̃s�N�Z���F��ConvertMode�Ŏw�肵�����т̃s�N�Z���F�ɕϊ�����SaveBinary�Ɋi�[���܂�
//�R���o�[�g���ꂽXRGB��f�l�͒ǉ�����`�Ŋi�[����܂��̂ŁA���ӂ��Ă��������B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//PixelConverter::ConvertPixel( <const UTXRGB &$InitVar> );
//<const UTXRGB &$InitVar>�F�ϊ����̃s�N�Z���F�\���̂��w�肵�܂��B
//*************************************************************************************************************************************************************
void PixelConverter::ConvertPixel( const UTXRGB &$InitVar ){
	
	UTXRGB15 fXRGB15Conv = {0,0,0,0};//XRGB15�s�N�Z���J���[�\���̕ϊ��p

	switch ( ConvertMode ) {
		
		case tMODE::RGB:
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			break;
		
		case tMODE::RGBA:
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::ARGB:
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//���ߓx�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			break;
		
		case tMODE::BGR:
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			break;
		
		case tMODE::BGRA:
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::XRGB:
			SaveBinary.Save( 0 , tX_RESERVED_VAL	);//�\��̈�̗v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			break;
		
		case tMODE::XRGB15:
			fXRGB15Conv.Reserved = 0;				//�\��̈�̗v�f��ݒ�
			fXRGB15Conv.Red		 = $InitVar.Red;	//�ԗv�f��ݒ�
			fXRGB15Conv.Green	 = $InitVar.Green;	//�Ηv�f��ݒ�
			fXRGB15Conv.Blue	 = $InitVar.Blue;	//�v�f��ݒ�
			SaveBinary.Save( 0 , *((UINT16*)(&fXRGB15Conv)) );//�\��̈�Ɛԗΐv�f��ۑ�
			break;
		
	}

}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//��XRGB15�̃s�N�Z���F��ConvertMode�Ŏw�肵�����т̃s�N�Z���F�ɕϊ�����SaveBinary�Ɋi�[����֐�
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//XRGB15�̃s�N�Z���F��ConvertMode�Ŏw�肵�����т̃s�N�Z���F�ɕϊ�����SaveBinary�Ɋi�[���܂�
//�R���o�[�g���ꂽXRGB15��f�l�͒ǉ�����`�Ŋi�[����܂��̂ŁA���ӂ��Ă��������B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//PixelConverter::ConvertPixel( <const UTXRGB15 &$InitVar> );
//<const UTXRGB15 &$InitVar>�F�ϊ����̃s�N�Z���F�\���̂��w�肵�܂��B
//*************************************************************************************************************************************************************
void PixelConverter::ConvertPixel( const UTXRGB15 &$InitVar ){
	
	UTXRGB15 fXRGB15Conv = {0,0,0,0};//XRGB15�s�N�Z���J���[�\���̕ϊ��p

	switch ( ConvertMode ) {
		
		case tMODE::RGB:
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			break;
		
		case tMODE::RGBA:
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::ARGB:
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//���ߓx�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			break;
		
		case tMODE::BGR:
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			break;
		
		case tMODE::BGRA:
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//���ߓx�v�f��ۑ�
			break;
		
		case tMODE::XRGB:
			SaveBinary.Save( 0 , tX_RESERVED_VAL	);//�\��̈�̗v�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Red		);//�ԗv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Green		);//�Ηv�f��ۑ�
			SaveBinary.Save( 0 , $InitVar.Blue		);//�v�f��ۑ�
			break;
		
		case tMODE::XRGB15:
			fXRGB15Conv.Reserved = 0;				//�\��̈�̗v�f��ݒ�
			fXRGB15Conv.Red		 = $InitVar.Red;	//�ԗv�f��ݒ�
			fXRGB15Conv.Green	 = $InitVar.Green;	//�Ηv�f��ݒ�
			fXRGB15Conv.Blue	 = $InitVar.Blue;	//�v�f��ݒ�
			SaveBinary.Save( 0 , *((UINT16*)(&fXRGB15Conv)) );//�\��̈�Ɛԗΐv�f��ۑ�
			break;
		
	}

}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//��SaveBinary�Ɏw�肵���o�C�g�����p�f�B���O��ǉ�����֐�
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//SaveBinary�Ɏw�肵���o�C�g�����̃p�f�B���O��ǉ����܂��B
//���̊֐��͓��Ƀ�������ŉ摜���쐬����ۂ�32bit��WORD���E�ɍ��킹��ړI�Ŏg�p���܂��B
//�ʏ�͍쐬����摜��32bit�ȉ��ɂȂ�ꍇ�ɉ摜�̊e�s�N�Z���s�Ō���ɕt�����܂��B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//RetData = PixelConverter::AddPading( <UINT8 $AddByteNum> );
//<UINT8 $AddByteNum>�F�p�f�B���O��ǉ�����o�C�g�����w�肵�܂��B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�Ԃ�l(bool)�z
//true �F�p�f�B���O�ǉ��ɐ���
//false�F�p�f�B���O�ǉ��Ɏ��s
//����{�I�Ɂufalse�v���Ԃ��Ă����ꍇ�͈��̌Ăяo���Œǉ��ł���o�C�g���𒴉߂��Ă���̂ŁutPADING_ADD_MAX�v�ȓ��Ɏ��߂�悤�ɂ��Ă��������B
//*************************************************************************************************************************************************************
bool PixelConverter::AddPading( UINT8 $AddByteNum ){
	if ( $AddByteNum > tPADING_ADD_MAX ) { return false; }//1��Œǉ��ł���o�C�g���𒴉߂��Ă���ꍇ�͊֐����I������B

	if ( $AddByteNum == 1 ) { SaveBinary.Save( 0 , ((char )0) ); }
	if ( $AddByteNum == 2 ) { SaveBinary.Save( 0 , ((short)0) ); }
	if ( $AddByteNum == 3 ) { SaveBinary.Save( 0 , ((short)0) ); SaveBinary.Save( 0 , ((char)0) ); }
	if ( $AddByteNum == 4 ) { SaveBinary.Save( 0 , ((int  )0) ); }

	return true;
}
//*************************************************************************************************************************************************************

}}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
