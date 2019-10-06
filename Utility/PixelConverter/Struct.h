/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//           ��f�̒��ڕ��ёւ������N���X[Struct��`]
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef INC_UT_PIXELCONVERTER_STRUCT_H//�܂��ǂݍ��܂�Ă��Ȃ���Έȉ��̏���������
#define INC_UT_PIXELCONVERTER_STRUCT_H//�u��f�̒��ڕ��ёւ������N���X�p-[Struct��`]�v�ǂݍ��݃t���O

#include "../../Include.h"							//�S�t�@�C����Include�\�ȃ\�[�X�܂Ƃ߃t�@�C��
#include "../Constant.h"							//���[�e�B���e�B�N���X�̒萔��`�t�@�C��

namespace AppStdLib{
namespace Utility{

using namespace std;		//�ustring�v�̖��O��ԁustd�v���w��
using namespace Const;		//Utility�萔�̖��O��ԁuConst�v���w��

//*************************************************************************************************************************************************************
//�������w��p�\����
//*************************************************************************************************************************************************************
struct UTRGB   { uint8_t  Red;      uint8_t  Green;   uint8_t  Blue;                       };//RGB�s�N�Z���J���[�w��p�\����
struct UTRGBA  { uint8_t  Red;      uint8_t  Green;   uint8_t  Blue;  uint8_t  Alpha;      };//RGBA�s�N�Z���J���[�w��p�\����
struct UTARGB  { uint8_t  Alpha;    uint8_t  Red;     uint8_t  Green; uint8_t  Blue;       };//ARGB�s�N�Z���J���[�w��p�\����
struct UTBGR   { uint8_t  Blue;     uint8_t  Green;   uint8_t  Red;                        };//BGR�s�N�Z���J���[�w��p�\����
struct UTBGRA  { uint8_t  Blue;     uint8_t  Green;   uint8_t  Red;   uint8_t  Alpha;      };//BGRA�s�N�Z���J���[�w��p�\����
struct UTXRGB  { uint8_t  Reserved; uint8_t  Red;     uint8_t  Green; uint8_t  Blue;       };//XRGB�s�N�Z���J���[�w��p�\����
struct UTXRGB15{ uint16_t Blue:5;   uint16_t Green:5; uint16_t Red:5; uint16_t Reserved:1; };//XRGB15�s�N�Z���J���[�w��p�\����
//*************************************************************************************************************************************************************

}}
#endif//INC_UT_PIXELCONVERTER_STRUCT_H
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
