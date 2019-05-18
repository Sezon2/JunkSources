/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           «‘ƒIƒuƒWƒFƒNƒgƒNƒ‰ƒX[ƒAƒNƒZƒTŠÖ˜A’è‹`]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../SwfPlayerLib.h"

namespace SwfPlayerLib{
namespace FLSystem{

//```````````````````````````````````````````````````````````````````````````````````
//«ˆÈ‰ºAsetterŒn¦–{ƒNƒ‰ƒX‚É’l‚ğƒZƒbƒg‚·‚éŒn

//*************************************************************************************************************************************************************
//š–{ƒNƒ‰ƒX‚Ìî•ñ‘S‚Ä‚ğİ’è‚·‚éŠÖ”
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//yà–¾z
//ˆø”‚Åw’è‚³‚ê‚½ADictionaryObjectƒIƒuƒWƒFƒNƒg‚ğ–{ƒNƒ‰ƒX‚É“o˜^‚µ‚Ü‚·B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//y‘®z
//SetDicObject( <const DictionaryObject &$DicObject> );
//<const DictionaryObject &$DicObject>Fİ’è‚·‚éDictionaryObjectƒNƒ‰ƒX‚ğw’è‚µ‚Ü‚·B
//@@¦È—ª•s‰ÂB
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
//š‚»‚Ì‘¼’P•i‚ÌsetterŒnŠÖ”ŒQ¦–{ƒNƒ‰ƒX‚É’l‚ğƒZƒbƒg‚·‚éŒn
//*************************************************************************************************************************************************************
void DictionaryObject::SetDicObject( const BitMap	 &$DicObject ){ DeleteDicObject(); CreateDicObject( tOBJECT_TYPE::BITMAP	); *((BitMap*	)DicObject) = $DicObject; }//–{ƒNƒ‰ƒX‚ÉBitMapî•ñ‚ğİ’è‚·‚éŠÖ”
void DictionaryObject::SetDicObject( const MovieClip &$DicObject ){ DeleteDicObject(); CreateDicObject( tOBJECT_TYPE::MOVIECLIP	); *((MovieClip*)DicObject) = $DicObject; }//–{ƒNƒ‰ƒX‚ÉMovieClipî•ñ‚ğİ’è‚·‚éŠÖ”
void DictionaryObject::SetDicObject( const Shape	 &$DicObject ){ DeleteDicObject(); CreateDicObject( tOBJECT_TYPE::SHAPE		); *((Shape*	)DicObject) = $DicObject; }//–{ƒNƒ‰ƒX‚ÉShapeî•ñ‚ğİ’è‚·‚éŠÖ”
//*************************************************************************************************************************************************************


//```````````````````````````````````````````````````````````````````````````````````
//«ˆÈ‰ºAgetterŒn¦–{ƒNƒ‰ƒX‚©‚ç’l‚ğ’ñ‹Ÿ‚·‚éŒn

//*************************************************************************************************************************************************************
//š‚»‚Ì‘¼’P•i‚ÌgetterŒnŠÖ”ŒQ¦–{ƒNƒ‰ƒX‚©‚ç’l‚ğ’ñ‹Ÿ‚·‚éŒn
//*************************************************************************************************************************************************************
tDIC_OBJECT_TYPE::ENUM DictionaryObject::GetDicType() const{ return DicType; }//–{ƒNƒ‰ƒX‚ÌƒtƒŒ[ƒ€–½—ßƒ^ƒCƒv‚Ì’l‚ğ•Ô‚·ŠÖ”
//----------------------------------------------------------------------
const BitMap*	 DictionaryObject::GetBitMapPtr		() const{ return (DicType == tOBJECT_TYPE::BITMAP	)? (BitMap*		)DicObject : NULL; }//–{ƒNƒ‰ƒX‚ÌDicObject‚ğBitMap‚Ìƒ|ƒCƒ“ƒ^‚É•ÏŠ·‚µ‚Ä•Ô‚·ŠÖ”
const MovieClip* DictionaryObject::GetMovieClipPtr	() const{ return (DicType == tOBJECT_TYPE::MOVIECLIP)? (MovieClip*	)DicObject : NULL; }//–{ƒNƒ‰ƒX‚ÌDicObject‚ğMovieClip‚Ìƒ|ƒCƒ“ƒ^‚É•ÏŠ·‚µ‚Ä•Ô‚·ŠÖ”
const Shape*	 DictionaryObject::GetShapePtr		() const{ return (DicType == tOBJECT_TYPE::SHAPE	)? (Shape*		)DicObject : NULL; }//–{ƒNƒ‰ƒX‚ÌDicObject‚ğShape‚Ìƒ|ƒCƒ“ƒ^‚É•ÏŠ·‚µ‚Ä•Ô‚·ŠÖ”
//----------------------------------------------------------------------
BitMap*		DictionaryObject::GetBitMapPtr	 (){ return (DicType == tOBJECT_TYPE::BITMAP	)? (BitMap*		)DicObject : NULL; }//–{ƒNƒ‰ƒX‚ÌDicObject‚ğBitMap‚Ìƒ|ƒCƒ“ƒ^‚É•ÏŠ·‚µ‚Ä•Ô‚·ŠÖ”
MovieClip*	DictionaryObject::GetMovieClipPtr(){ return (DicType == tOBJECT_TYPE::MOVIECLIP	)? (MovieClip*	)DicObject : NULL; }//–{ƒNƒ‰ƒX‚ÌDicObject‚ğMovieClip‚Ìƒ|ƒCƒ“ƒ^‚É•ÏŠ·‚µ‚Ä•Ô‚·ŠÖ”
Shape*		DictionaryObject::GetShapePtr	 (){ return (DicType == tOBJECT_TYPE::SHAPE		)? (Shape*		)DicObject : NULL; }//–{ƒNƒ‰ƒX‚ÌDicObject‚ğShape‚Ìƒ|ƒCƒ“ƒ^‚É•ÏŠ·‚µ‚Ä•Ô‚·ŠÖ”
//*************************************************************************************************************************************************************

}}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
