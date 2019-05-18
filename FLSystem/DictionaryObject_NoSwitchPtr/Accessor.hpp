/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           �����I�u�W�F�N�g�N���X[�A�N�Z�T�֘A��`]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../../SwfPlayerLib.h"

namespace SwfPlayerLib{
namespace FLSystem{

//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
//���ȉ��Asetter�n���{�N���X�ɒl���Z�b�g����n

//*************************************************************************************************************************************************************
//���{�N���X�̏��S�Ă�ݒ肷��֐�
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//�����Ŏw�肳�ꂽ�ADictionaryObject�I�u�W�F�N�g��{�N���X�ɓo�^���܂��B
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//�y�����z
//SetDicObject( <const DictionaryObject &$DicObject> );
//<const DictionaryObject &$DicObject>�F�ݒ肷��DictionaryObject�N���X���w�肵�܂��B
//�@�@���ȗ��s�B
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
//�����̑��P�i��setter�n�֐��Q���{�N���X�ɒl���Z�b�g����n
//*************************************************************************************************************************************************************
void DictionaryObject::SetDicObject( const BitMap	 &$DicObject ){ DeleteDicObject(); CreateDicObject( tOBJECT_TYPE::BITMAP	); *((BitMap*	)DicObject) = $DicObject; }//�{�N���X��BitMap����ݒ肷��֐�
void DictionaryObject::SetDicObject( const MovieClip &$DicObject ){ DeleteDicObject(); CreateDicObject( tOBJECT_TYPE::MOVIECLIP	); *((MovieClip*)DicObject) = $DicObject; }//�{�N���X��MovieClip����ݒ肷��֐�
void DictionaryObject::SetDicObject( const Shape	 &$DicObject ){ DeleteDicObject(); CreateDicObject( tOBJECT_TYPE::SHAPE		); *((Shape*	)DicObject) = $DicObject; }//�{�N���X��Shape����ݒ肷��֐�
//*************************************************************************************************************************************************************


//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
//���ȉ��Agetter�n���{�N���X����l��񋟂���n

//*************************************************************************************************************************************************************
//�����̑��P�i��getter�n�֐��Q���{�N���X����l��񋟂���n
//*************************************************************************************************************************************************************
tDIC_OBJECT_TYPE::ENUM DictionaryObject::GetDicType() const{ return DicType; }//�{�N���X�̃t���[�����߃^�C�v�̒l��Ԃ��֐�
//----------------------------------------------------------------------
const BitMap*	 DictionaryObject::GetBitMapPtr		() const{ return (DicType == tOBJECT_TYPE::BITMAP	)? (BitMap*		)DicObject : NULL; }//�{�N���X��DicObject��BitMap�̃|�C���^�ɕϊ����ĕԂ��֐�
const MovieClip* DictionaryObject::GetMovieClipPtr	() const{ return (DicType == tOBJECT_TYPE::MOVIECLIP)? (MovieClip*	)DicObject : NULL; }//�{�N���X��DicObject��MovieClip�̃|�C���^�ɕϊ����ĕԂ��֐�
const Shape*	 DictionaryObject::GetShapePtr		() const{ return (DicType == tOBJECT_TYPE::SHAPE	)? (Shape*		)DicObject : NULL; }//�{�N���X��DicObject��Shape�̃|�C���^�ɕϊ����ĕԂ��֐�
//----------------------------------------------------------------------
BitMap*		DictionaryObject::GetBitMapPtr	 (){ return (DicType == tOBJECT_TYPE::BITMAP	)? (BitMap*		)DicObject : NULL; }//�{�N���X��DicObject��BitMap�̃|�C���^�ɕϊ����ĕԂ��֐�
MovieClip*	DictionaryObject::GetMovieClipPtr(){ return (DicType == tOBJECT_TYPE::MOVIECLIP	)? (MovieClip*	)DicObject : NULL; }//�{�N���X��DicObject��MovieClip�̃|�C���^�ɕϊ����ĕԂ��֐�
Shape*		DictionaryObject::GetShapePtr	 (){ return (DicType == tOBJECT_TYPE::SHAPE		)? (Shape*		)DicObject : NULL; }//�{�N���X��DicObject��Shape�̃|�C���^�ɕϊ����ĕԂ��֐�
//*************************************************************************************************************************************************************

}}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
