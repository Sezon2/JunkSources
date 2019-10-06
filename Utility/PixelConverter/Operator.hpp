/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           画素の直接並び替え処理クラス[各種オペレータ定義]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "PixelConverter.h"

namespace AppStdLib{
namespace Utility{

//*************************************************************************************************************************************************************
//★代入演算子(=)を行なう関数
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【説明】
//代入演算子(=)の処理を行ないます。
//※処理内容が2行以上になったらここにまとめないで独立させてください。
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【書式】
//objvar = <代入する値/変数>;
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
