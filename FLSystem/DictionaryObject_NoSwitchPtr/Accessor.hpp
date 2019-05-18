/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           辞書オブジェクトクラス[アクセサ関連定義]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../SwfPlayerLib.h"

namespace SwfPlayerLib{
namespace FLSystem{

//〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜
//↓以下、setter系※本クラスに値をセットする系

//*************************************************************************************************************************************************************
//★本クラスの情報全てを設定する関数
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【説明】
//引数で指定された、DictionaryObjectオブジェクトを本クラスに登録します。
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//【書式】
//SetDicObject( <const DictionaryObject &$DicObject> );
//<const DictionaryObject &$DicObject>：設定するDictionaryObjectクラスを指定します。
//　　※省略不可。
//*************************************************************************************************************************************************************
void DictionaryObject::SetDicObject( const DictionaryObject &$DicObject ){
	
	DeleteDicObject();
	CreateDicObject( $DicObject.DicType );

	if ( $DicObject.DicType == tOBJECT_TYPE::BITMAP		) { *((BitMap*	 )DicObject) = *((BitMap*	)$DicObject.DicObject); }else
	if ( $DicObject.DicType == tOBJECT_TYPE::MOVIECLIP	) { *((MovieClip*)DicObject) = *((MovieClip*)$DicObject.DicObject); }else
	if ( $DicObject.DicType == tOBJECT_TYPE::SHAPE		) { *((Shape*	 )DicObject) = *((Shape*	)$DicObject.DicObject); }

}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//★その他単品のsetter系関数群※本クラスに値をセットする系
//*************************************************************************************************************************************************************
void DictionaryObject::SetDicObject( const BitMap	 &$DicObject ){ DeleteDicObject(); CreateDicObject( tOBJECT_TYPE::BITMAP	); *((BitMap*	)DicObject) = $DicObject; }//本クラスにBitMap情報を設定する関数
void DictionaryObject::SetDicObject( const MovieClip &$DicObject ){ DeleteDicObject(); CreateDicObject( tOBJECT_TYPE::MOVIECLIP	); *((MovieClip*)DicObject) = $DicObject; }//本クラスにMovieClip情報を設定する関数
void DictionaryObject::SetDicObject( const Shape	 &$DicObject ){ DeleteDicObject(); CreateDicObject( tOBJECT_TYPE::SHAPE		); *((Shape*	)DicObject) = $DicObject; }//本クラスにShape情報を設定する関数
//*************************************************************************************************************************************************************


//〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜
//↓以下、getter系※本クラスから値を提供する系

//*************************************************************************************************************************************************************
//★その他単品のgetter系関数群※本クラスから値を提供する系
//*************************************************************************************************************************************************************
tDIC_OBJECT_TYPE::ENUM DictionaryObject::GetDicType() const{ return DicType; }//本クラスのフレーム命令タイプの値を返す関数
//----------------------------------------------------------------------
const BitMap*	 DictionaryObject::GetBitMapPtr		() const{ return (DicType == tOBJECT_TYPE::BITMAP	)? (BitMap*		)DicObject : NULL; }//本クラスのDicObjectをBitMapのポインタに変換して返す関数
const MovieClip* DictionaryObject::GetMovieClipPtr	() const{ return (DicType == tOBJECT_TYPE::MOVIECLIP)? (MovieClip*	)DicObject : NULL; }//本クラスのDicObjectをMovieClipのポインタに変換して返す関数
const Shape*	 DictionaryObject::GetShapePtr		() const{ return (DicType == tOBJECT_TYPE::SHAPE	)? (Shape*		)DicObject : NULL; }//本クラスのDicObjectをShapeのポインタに変換して返す関数
//----------------------------------------------------------------------
BitMap*		DictionaryObject::GetBitMapPtr	 (){ return (DicType == tOBJECT_TYPE::BITMAP	)? (BitMap*		)DicObject : NULL; }//本クラスのDicObjectをBitMapのポインタに変換して返す関数
MovieClip*	DictionaryObject::GetMovieClipPtr(){ return (DicType == tOBJECT_TYPE::MOVIECLIP	)? (MovieClip*	)DicObject : NULL; }//本クラスのDicObjectをMovieClipのポインタに変換して返す関数
Shape*		DictionaryObject::GetShapePtr	 (){ return (DicType == tOBJECT_TYPE::SHAPE		)? (Shape*		)DicObject : NULL; }//本クラスのDicObjectをShapeのポインタに変換して返す関数
//*************************************************************************************************************************************************************

}}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
