/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           画素の直接並び替え処理クラス[デバッグ機能関連定義]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "PixelConverter.h"

namespace AppStdLib{
namespace Utility{

//*************************************************************************************************************************************************************
//★各種機能のデバッグ実行関数
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【説明】
//各種機能のデバッグ実行を行ないます。
//基本的に本クラスのデバッグはここで行なってください。
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【書式】
//DebugExec();
//*************************************************************************************************************************************************************
void PixelConverter::DebugExec(){
	
	/*//■シンプルな使用方法でテスト
	UTRGB	TestRGB		= { 0xFA , 0xA1 , 0x10 };
	UTRGB*	TestRGBPtr	= &TestRGB;//メモリの状態確認したいので。
	//-------------------------------------------
	PixelConverter::SetConvertMode( tPIXEL::CONVERT::MODE::BGR );//変換モードを設定。
	PixelConverter TestConverter = TestRGB;//実体の作成と同時に代入してコンバートするテスト。*/

	//■バイナリに保存した連続したピクセルデータをvectorを通して変換するテスト
	Binary					TestImgPixelBin;//テスト用画像ピクセルデータ
	UTRGB*					TestRGBPtr		= NULL;
	vector<PixelConverter>* TestConverter	= NULL;//一括変換用のvector。
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
	PixelConverter::SetConvertMode( tMODE::BGR );//変換モードを設定。
	TestRGBPtr = (UTRGB*)TestImgPixelBin.GetSvBinaryPtr();//保存しているバイナリのポインタをUTRGBのポインタに偽装する。
	TestConverter = new vector<PixelConverter>( TestRGBPtr , TestRGBPtr + (TestImgPixelBin.GetBinarySizeRef()/sizeof(UTRGB)) );
	delete TestConverter;//使い終わったvectorを削除する。
	TestConverter = NULL;//削除したらNULLにしておく。
	PixelConverter::SetConvertMode( tMODE::RESET );//使い終わったらリセットする。

	//■クラスサイズ確認
	UINT Size = sizeof(PixelConverter);

}
//*************************************************************************************************************************************************************

}}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
