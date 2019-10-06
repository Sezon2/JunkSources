/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           画素の直接並び替え処理クラス[基本機能関連定義]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "PixelConverter.h"

namespace AppStdLib{
namespace Utility{

//*************************************************************************************************************************************************************
//★RGBのピクセル色をConvertModeで指定した並びのピクセル色に変換してSaveBinaryに格納する関数
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【説明】
//RGBのピクセル色をConvertModeで指定した並びのピクセル色に変換してSaveBinaryに格納します。
//コンバートされたRGB画素値は追加する形で格納されますので、注意してください。
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【書式】
//PixelConverter::ConvertPixel( <const UTRGB &$InitVar> );
//<const UTRGB &$InitVar>：変換元のピクセル色構造体を指定します。
//*************************************************************************************************************************************************************
void PixelConverter::ConvertPixel( const UTRGB &$InitVar ){
	
	UTXRGB15 fXRGB15Conv = {0,0,0,0};//XRGB15ピクセルカラー構造体変換用

	switch ( ConvertMode ) {
		
		case tMODE::RGB:
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			break;
		
		case tMODE::RGBA:
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//透過度要素を保存
			break;
		
		case tMODE::ARGB:
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//透過度要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			break;
		
		case tMODE::BGR:
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			break;
		
		case tMODE::BGRA:
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//透過度要素を保存
			break;
		
		case tMODE::XRGB:
			SaveBinary.Save( 0 , tX_RESERVED_VAL	);//予約領域の要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			break;
		
		case tMODE::XRGB15:
			fXRGB15Conv.Reserved = 0;				//予約領域の要素を設定
			fXRGB15Conv.Red		 = $InitVar.Red;	//赤要素を設定
			fXRGB15Conv.Green	 = $InitVar.Green;	//緑要素を設定
			fXRGB15Conv.Blue	 = $InitVar.Blue;	//青要素を設定
			SaveBinary.Save( 0 , *((UINT16*)(&fXRGB15Conv)) );//予約領域と赤緑青要素を保存
			break;
		
	}

}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//★RGBAのピクセル色をConvertModeで指定した並びのピクセル色に変換してSaveBinaryに格納する関数
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【説明】
//RGBAのピクセル色をConvertModeで指定した並びのピクセル色に変換してSaveBinaryに格納します。
//コンバートされたRGBA画素値は追加する形で格納されますので、注意してください。
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【書式】
//PixelConverter::ConvertPixel( <const UTRGBA &$InitVar> );
//<const UTRGBA &$InitVar>：変換元のピクセル色構造体を指定します。
//*************************************************************************************************************************************************************
void PixelConverter::ConvertPixel( const UTRGBA &$InitVar ){
	
	UTXRGB15 fXRGB15Conv = {0,0,0,0};//XRGB15ピクセルカラー構造体変換用

	switch ( ConvertMode ) {
		
		case tMODE::RGB:
			SaveBinary	 .Save( 0 , $InitVar.Red	);//赤要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Green	);//緑要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//青要素を保存
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//透過度要素を保存
			break;
		
		case tMODE::RGBA:
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , $InitVar.Alpha		);//透過度要素を保存
			break;
		
		case tMODE::ARGB:
			SaveBinary.Save( 0 , $InitVar.Alpha		);//透過度要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			break;
		
		case tMODE::BGR:
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//青要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Green	);//緑要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Red	);//赤要素を保存
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//透過度要素を保存
			break;
		
		case tMODE::BGRA:
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Alpha		);//透過度要素を保存
			break;
		
		case tMODE::XRGB:
			SaveBinary	 .Save( 0 , tX_RESERVED_VAL	);//予約領域の要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Red	);//赤要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Green	);//緑要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//青要素を保存
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//透過度要素を保存
			break;
		
		case tMODE::XRGB15:
			fXRGB15Conv.Reserved = 0;				//予約領域の要素を設定
			fXRGB15Conv.Red		 = $InitVar.Red;	//赤要素を設定
			fXRGB15Conv.Green	 = $InitVar.Green;	//緑要素を設定
			fXRGB15Conv.Blue	 = $InitVar.Blue;	//青要素を設定
			SaveBinary	 .Save( 0 , *((UINT16*)(&fXRGB15Conv))	);//予約領域と赤緑青要素を保存
			DestAlphaData.Save( 0 , $InitVar.Alpha				);//透過度要素を保存
			break;
		
	}

}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//★ARGBのピクセル色をConvertModeで指定した並びのピクセル色に変換してSaveBinaryに格納する関数
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【説明】
//ARGBのピクセル色をConvertModeで指定した並びのピクセル色に変換してSaveBinaryに格納します。
//コンバートされたARGB画素値は追加する形で格納されますので、注意してください。
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【書式】
//PixelConverter::ConvertPixel( <const UTARGB &$InitVar> );
//<const UTARGB &$InitVar>：変換元のピクセル色構造体を指定します。
//*************************************************************************************************************************************************************
void PixelConverter::ConvertPixel( const UTARGB &$InitVar ){
	
	UTXRGB15 fXRGB15Conv = {0,0,0,0};//XRGB15ピクセルカラー構造体変換用

	switch ( ConvertMode ) {
		
		case tMODE::RGB:
			SaveBinary	 .Save( 0 , $InitVar.Red	);//赤要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Green	);//緑要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//青要素を保存
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//透過度要素を保存
			break;
		
		case tMODE::RGBA:
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , $InitVar.Alpha		);//透過度要素を保存
			break;
		
		case tMODE::ARGB:
			SaveBinary.Save( 0 , $InitVar.Alpha		);//透過度要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			break;
		
		case tMODE::BGR:
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//青要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Green	);//緑要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Red	);//赤要素を保存
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//透過度要素を保存
			break;
		
		case tMODE::BGRA:
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Alpha		);//透過度要素を保存
			break;
		
		case tMODE::XRGB:
			SaveBinary	 .Save( 0 , tX_RESERVED_VAL	);//予約領域の要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Red	);//赤要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Green	);//緑要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//青要素を保存
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//透過度要素を保存
			break;
		
		case tMODE::XRGB15:
			fXRGB15Conv.Reserved = 0;				//予約領域の要素を設定
			fXRGB15Conv.Red		 = $InitVar.Red;	//赤要素を設定
			fXRGB15Conv.Green	 = $InitVar.Green;	//緑要素を設定
			fXRGB15Conv.Blue	 = $InitVar.Blue;	//青要素を設定
			SaveBinary	 .Save( 0 , *((UINT16*)(&fXRGB15Conv))	);//予約領域と赤緑青要素を保存
			DestAlphaData.Save( 0 , $InitVar.Alpha				);//透過度要素を保存
			break;
		
	}

}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//★BGRのピクセル色をConvertModeで指定した並びのピクセル色に変換してSaveBinaryに格納する関数
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【説明】
//BGRのピクセル色をConvertModeで指定した並びのピクセル色に変換してSaveBinaryに格納します。
//コンバートされたBGR画素値は追加する形で格納されますので、注意してください。
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【書式】
//PixelConverter::ConvertPixel( <const UTBGR &$InitVar> );
//<const UTBGR &$InitVar>：変換元のピクセル色構造体を指定します。
//*************************************************************************************************************************************************************
void PixelConverter::ConvertPixel( const UTBGR &$InitVar ){
	
	UTXRGB15 fXRGB15Conv = {0,0,0,0};//XRGB15ピクセルカラー構造体変換用

	switch ( ConvertMode ) {
		
		case tMODE::RGB:
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			break;
		
		case tMODE::RGBA:
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//透過度要素を保存
			break;
		
		case tMODE::ARGB:
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//透過度要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			break;
		
		case tMODE::BGR:
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			break;
		
		case tMODE::BGRA:
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//透過度要素を保存
			break;
		
		case tMODE::XRGB:
			SaveBinary.Save( 0 , tX_RESERVED_VAL	);//予約領域の要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			break;
		
		case tMODE::XRGB15:
			fXRGB15Conv.Reserved = 0;				//予約領域の要素を設定
			fXRGB15Conv.Red		 = $InitVar.Red;	//赤要素を設定
			fXRGB15Conv.Green	 = $InitVar.Green;	//緑要素を設定
			fXRGB15Conv.Blue	 = $InitVar.Blue;	//青要素を設定
			SaveBinary.Save( 0 , *((UINT16*)(&fXRGB15Conv)) );//予約領域と赤緑青要素を保存
			break;
		
	}

}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//★BGRAのピクセル色をConvertModeで指定した並びのピクセル色に変換してSaveBinaryに格納する関数
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【説明】
//BGRAのピクセル色をConvertModeで指定した並びのピクセル色に変換してSaveBinaryに格納します。
//コンバートされたBGRA画素値は追加する形で格納されますので、注意してください。
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【書式】
//PixelConverter::ConvertPixel( <const UTBGRA &$InitVar> );
//<const UTBGRA &$InitVar>：変換元のピクセル色構造体を指定します。
//*************************************************************************************************************************************************************
void PixelConverter::ConvertPixel( const UTBGRA	&$InitVar ){
	
	UTXRGB15 fXRGB15Conv = {0,0,0,0};//XRGB15ピクセルカラー構造体変換用

	switch ( ConvertMode ) {
		
		case tMODE::RGB:
			SaveBinary	 .Save( 0 , $InitVar.Red	);//赤要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Green	);//緑要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//青要素を保存
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//透過度要素を保存
			break;
		
		case tMODE::RGBA:
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , $InitVar.Alpha		);//透過度要素を保存
			break;
		
		case tMODE::ARGB:
			SaveBinary.Save( 0 , $InitVar.Alpha		);//透過度要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			break;
		
		case tMODE::BGR:
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//青要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Green	);//緑要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Red	);//赤要素を保存
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//透過度要素を保存
			break;
		
		case tMODE::BGRA:
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Alpha		);//透過度要素を保存
			break;
		
		case tMODE::XRGB:
			SaveBinary	 .Save( 0 , tX_RESERVED_VAL	);//予約領域の要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Red	);//赤要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Green	);//緑要素を保存
			SaveBinary	 .Save( 0 , $InitVar.Blue	);//青要素を保存
			DestAlphaData.Save( 0 , $InitVar.Alpha	);//透過度要素を保存
			break;
		
		case tMODE::XRGB15:
			fXRGB15Conv.Reserved = 0;				//予約領域の要素を設定
			fXRGB15Conv.Red		 = $InitVar.Red;	//赤要素を設定
			fXRGB15Conv.Green	 = $InitVar.Green;	//緑要素を設定
			fXRGB15Conv.Blue	 = $InitVar.Blue;	//青要素を設定
			SaveBinary	 .Save( 0 , *((UINT16*)(&fXRGB15Conv))	);//予約領域と赤緑青要素を保存
			DestAlphaData.Save( 0 , $InitVar.Alpha				);//透過度要素を保存
			break;
		
	}

}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//★XRGBのピクセル色をConvertModeで指定した並びのピクセル色に変換してSaveBinaryに格納する関数
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【説明】
//XRGBのピクセル色をConvertModeで指定した並びのピクセル色に変換してSaveBinaryに格納します
//コンバートされたXRGB画素値は追加する形で格納されますので、注意してください。
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【書式】
//PixelConverter::ConvertPixel( <const UTXRGB &$InitVar> );
//<const UTXRGB &$InitVar>：変換元のピクセル色構造体を指定します。
//*************************************************************************************************************************************************************
void PixelConverter::ConvertPixel( const UTXRGB &$InitVar ){
	
	UTXRGB15 fXRGB15Conv = {0,0,0,0};//XRGB15ピクセルカラー構造体変換用

	switch ( ConvertMode ) {
		
		case tMODE::RGB:
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			break;
		
		case tMODE::RGBA:
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//透過度要素を保存
			break;
		
		case tMODE::ARGB:
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//透過度要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			break;
		
		case tMODE::BGR:
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			break;
		
		case tMODE::BGRA:
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//透過度要素を保存
			break;
		
		case tMODE::XRGB:
			SaveBinary.Save( 0 , tX_RESERVED_VAL	);//予約領域の要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			break;
		
		case tMODE::XRGB15:
			fXRGB15Conv.Reserved = 0;				//予約領域の要素を設定
			fXRGB15Conv.Red		 = $InitVar.Red;	//赤要素を設定
			fXRGB15Conv.Green	 = $InitVar.Green;	//緑要素を設定
			fXRGB15Conv.Blue	 = $InitVar.Blue;	//青要素を設定
			SaveBinary.Save( 0 , *((UINT16*)(&fXRGB15Conv)) );//予約領域と赤緑青要素を保存
			break;
		
	}

}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//★XRGB15のピクセル色をConvertModeで指定した並びのピクセル色に変換してSaveBinaryに格納する関数
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【説明】
//XRGB15のピクセル色をConvertModeで指定した並びのピクセル色に変換してSaveBinaryに格納します
//コンバートされたXRGB15画素値は追加する形で格納されますので、注意してください。
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【書式】
//PixelConverter::ConvertPixel( <const UTXRGB15 &$InitVar> );
//<const UTXRGB15 &$InitVar>：変換元のピクセル色構造体を指定します。
//*************************************************************************************************************************************************************
void PixelConverter::ConvertPixel( const UTXRGB15 &$InitVar ){
	
	UTXRGB15 fXRGB15Conv = {0,0,0,0};//XRGB15ピクセルカラー構造体変換用

	switch ( ConvertMode ) {
		
		case tMODE::RGB:
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			break;
		
		case tMODE::RGBA:
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//透過度要素を保存
			break;
		
		case tMODE::ARGB:
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//透過度要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			break;
		
		case tMODE::BGR:
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			break;
		
		case tMODE::BGRA:
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , tALPHA_CHANNEL_MAX	);//透過度要素を保存
			break;
		
		case tMODE::XRGB:
			SaveBinary.Save( 0 , tX_RESERVED_VAL	);//予約領域の要素を保存
			SaveBinary.Save( 0 , $InitVar.Red		);//赤要素を保存
			SaveBinary.Save( 0 , $InitVar.Green		);//緑要素を保存
			SaveBinary.Save( 0 , $InitVar.Blue		);//青要素を保存
			break;
		
		case tMODE::XRGB15:
			fXRGB15Conv.Reserved = 0;				//予約領域の要素を設定
			fXRGB15Conv.Red		 = $InitVar.Red;	//赤要素を設定
			fXRGB15Conv.Green	 = $InitVar.Green;	//緑要素を設定
			fXRGB15Conv.Blue	 = $InitVar.Blue;	//青要素を設定
			SaveBinary.Save( 0 , *((UINT16*)(&fXRGB15Conv)) );//予約領域と赤緑青要素を保存
			break;
		
	}

}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//★SaveBinaryに指定したバイト数分パディングを追加する関数
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【説明】
//SaveBinaryに指定したバイト数分のパディングを追加します。
//この関数は特にメモリ上で画像を作成する際に32bitのWORD境界に合わせる目的で使用します。
//通常は作成する画像が32bit以下になる場合に画像の各ピクセル行最後尾に付加します。
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【書式】
//RetData = PixelConverter::AddPading( <UINT8 $AddByteNum> );
//<UINT8 $AddByteNum>：パディングを追加するバイト数を指定します。
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【返る値(bool)】
//true ：パディング追加に成功
//false：パディング追加に失敗
//※基本的に「false」が返ってきた場合は一回の呼び出しで追加できるバイト数を超過しているので「tPADING_ADD_MAX」以内に収めるようにしてください。
//*************************************************************************************************************************************************************
bool PixelConverter::AddPading( UINT8 $AddByteNum ){
	if ( $AddByteNum > tPADING_ADD_MAX ) { return false; }//1回で追加できるバイト数を超過している場合は関数を終了する。

	if ( $AddByteNum == 1 ) { SaveBinary.Save( 0 , ((char )0) ); }
	if ( $AddByteNum == 2 ) { SaveBinary.Save( 0 , ((short)0) ); }
	if ( $AddByteNum == 3 ) { SaveBinary.Save( 0 , ((short)0) ); SaveBinary.Save( 0 , ((char)0) ); }
	if ( $AddByteNum == 4 ) { SaveBinary.Save( 0 , ((int  )0) ); }

	return true;
}
//*************************************************************************************************************************************************************

}}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
