#include <windows.h>

#define  ACC_PUBLIC		0x1
#define ACC_PRIVATE		0x2
#define ACC_PROTECTED	0x4
#define ACC_STATIC		0x8
#define NO_INDEX  0xffffffff




struct DexHeader
{
	byte MAGIC[8];
	UINT32 checksum;
	byte signature[20];
	UINT32 file_size;
	UINT32 header_size;
	UINT32 endian_tag;
	UINT32 link_size;
	UINT32 link_off;
	UINT32 map_off;
	UINT32 string_ids_size;
	UINT32 string_ids_off;

	//uint string_ids_size[4];
	//uint string_ids_off[4];
	
	UINT32 type_ids_size;
	UINT32 type_ids_off;
	UINT32 proto_ids_size;
	UINT32 proto_ids_off;
	UINT32 field_ids_size;
	UINT32 field_ids_off;
	UINT32 method_ids_size;
	UINT32 method_ids_off;
	UINT32 class_defs_size;
	UINT32 class_defs_off;
	UINT32 data_size;
	UINT32 data_off;	
	};

struct proto_id_item
{
	UINT32 shorty_idx;
	UINT32 return_type_idx;
	UINT32 parameters_offset;
};

struct filed_id_item
{
	unsigned short  class_idx;		//index of type_ids 
	unsigned short	type_idx;		//index of type_ids 		
	UINT32			name_idx;		//index of string_ids 
};

struct method_id_item
{
	unsigned short  class_idx;		//index of type_ids 	
	unsigned short  proto_idx;		//index of proto_ids 	
	UINT32			name_idx;		//index of string_ids 	
};

class Class_dex
{
public:
DexHeader *Pdexheader;
};

struct class_def_item 
{
	UINT32  class_idx;			//��������� class ����,idx of type_ids
	UINT32  access_flags;		//���� class �ķ������� ���� public , final , static ��				
	UINT32	superclass_idx;		//�������������,idx of type_ids
	UINT32  interfaces_off;		//ָ�� class �� interfaces(�ӿ�), ��ָ������ݽṹΪ type_list,���޽ӿڣ�ֵΪ0
	UINT32  source_file_idx;	//��ʾԴ�����ļ�����Ϣ,ֵ��string_ids��һ�� index.��������Ϣȱʧ,����ֵ��ֵΪNO_INDEX=0xffff ffff  
	UINT32	annotations_off;	//ֵ��һ��ƫ�Ƶ�ַ ��ָ��������Ǹ� class ��ע�� ��λ���� data ������ʽΪ annotations_direcotry_item ����û�д������� ��ֵΪ 0 ��
	UINT32  class_data_off;		//ָ��class_data_item[]
	UINT32  static_value_off;	//ָ�� data �����һ��list,��ʽΪ encoded_array_item
};