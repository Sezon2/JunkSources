/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           �����I�u�W�F�N�g�N���X[��{�@�\�֘A��`]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../SwfPlayerLib.h"

namespace SwfPlayerLib{
namespace FLSystem{

//*************************************************************************************************************************************************************
//���{�N���X��DictionaryObject��񂪎w�肳�ꂽDictionaryObject���Ɠ����ł��邩�m�F����֐�
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//�{�N���X��DictionaryObject��񂪎w�肳�ꂽDictionaryObject���Ɠ����ł��邩�m�F���Č��ʂ�Ԃ��܂��B
//��ɃI�y���[�^���Z�q�Ŏg������z�肵�����ł����A���ڌĂ�ł��\���܂���B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//RetData = isSame( <const DictionaryObject &$CalcNum> );
//<const DictionaryObject &$CalcNum>�F�m�F������DictionaryObject�N���X���w�肵�܂��B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�Ԃ�l(bool)�z
//true �������ƃN���X�̏��͓����ł��B
//false�������ƃN���X�̏��͈قȂ��Ă��܂��B
//*************************************************************************************************************************************************************
bool DictionaryObject::isSame( const DictionaryObject &$CalcNum ) const{
	
	bool RetData = false;//�Ԃ��f�[�^

	if ( DicType == $CalcNum.DicType ) {
		//�����g�ƈ����̎����I�u�W�F�N�g�^�C�v�������^�C�v�̏ꍇ
		if ( DicType == tOBJECT_TYPE::BITMAP	) { if ( *GetBitMapPtr	 ()	== *$CalcNum.GetBitMapPtr	()	) { RetData = true; }else{ return false; } }else
		if ( DicType == tOBJECT_TYPE::MOVIECLIP	) { if ( *GetMovieClipPtr()	== *$CalcNum.GetMovieClipPtr()	) { RetData = true; }else{ return false; } }else
		if ( DicType == tOBJECT_TYPE::SHAPE		) { if ( *GetShapePtr	 ()	== *$CalcNum.GetShapePtr	()	) { RetData = true; }else{ return false; } }else
		if ( DicType == tOBJECT_TYPE::UNDEFINED	) { RetData = true; }
	}else{ return false; }

	return RetData;
}
//*************************************************************************************************************************************************************


//*************************************************************************************************************************************************************
//�����̑��P�i�̊֐��Q
//*************************************************************************************************************************************************************
bool DictionaryObject::isSame( const BitMap		&$CalcNum ) const{ return ((DicType == tOBJECT_TYPE::BITMAP		)? ((*GetBitMapPtr	 () == $CalcNum)? true : false) : false); }//�{�N���X��DictionaryObject��񂪎w�肳�ꂽBitMap���Ɠ����ł��邩�m�F����֐�
bool DictionaryObject::isSame( const MovieClip	&$CalcNum ) const{ return ((DicType == tOBJECT_TYPE::MOVIECLIP	)? ((*GetMovieClipPtr() == $CalcNum)? true : false) : false); }//�{�N���X��DictionaryObject��񂪎w�肳�ꂽMovieClip���Ɠ����ł��邩�m�F����֐�
bool DictionaryObject::isSame( const Shape		&$CalcNum ) const{ return ((DicType == tOBJECT_TYPE::SHAPE		)? ((*GetShapePtr	 () == $CalcNum)? true : false) : false); }//�{�N���X��DictionaryObject��񂪎w�肳�ꂽShape���Ɠ����ł��邩�m�F����֐�
//*************************************************************************************************************************************************************

}}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
