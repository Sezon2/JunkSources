/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           ��f�̒��ڕ��ёւ������N���X[�e��I�y���[�^��`]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "PixelConverter.h"

namespace AppStdLib{
namespace Utility{

//*************************************************************************************************************************************************************
//��������Z�q(=)���s�Ȃ��֐�
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//������Z�q(=)�̏������s�Ȃ��܂��B
//���������e��2�s�ȏ�ɂȂ����炱���ɂ܂Ƃ߂Ȃ��œƗ������Ă��������B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//objvar = <�������l/�ϐ�>;
//*************************************************************************************************************************************************************
PixelConverter &PixelConverter::operator=( const UTRGB			&$CalcNum ){ ConvertPixel( $CalcNum ); return *this; }
PixelConverter &PixelConverter::operator=( const UTRGBA			&$CalcNum ){ ConvertPixel( $CalcNum ); return *this; }
PixelConverter &PixelConverter::operator=( const UTARGB			&$CalcNum ){ ConvertPixel( $CalcNum ); return *this; }
PixelConverter &PixelConverter::operator=( const UTBGR			&$CalcNum ){ ConvertPixel( $CalcNum ); return *this; }
PixelConverter &PixelConverter::operator=( const UTBGRA			&$CalcNum ){ ConvertPixel( $CalcNum ); return *this; }
PixelConverter &PixelConverter::operator=( const UTXRGB			&$CalcNum ){ ConvertPixel( $CalcNum ); return *this; }
PixelConverter &PixelConverter::operator=( const UTXRGB15		&$CalcNum ){ ConvertPixel( $CalcNum ); return *this; }
PixelConverter &PixelConverter::operator=( const PixelConverter	&$CalcNum ){ return *this; }
//*************************************************************************************************************************************************************

}}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
