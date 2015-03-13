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
	UINT32  class_idx;			//描述具体的 class 类型,idx of type_ids
	UINT32  access_flags;		//描述 class 的访问类型 ，如 public , final , static 等				
	UINT32	superclass_idx;		//描述父类的类型,idx of type_ids
	UINT32  interfaces_off;		//指向 class 的 interfaces(接口), 被指向的数据结构为 type_list,若无接口，值为0
	UINT32  source_file_idx;	//表示源代码文件的信息,值是string_ids的一个 index.若此项信息缺失,此项值赋值为NO_INDEX=0xffff ffff  
	UINT32	annotations_off;	//值是一个偏移地址 ，指向的内容是该 class 的注释 ，位置在 data 区，格式为 annotations_direcotry_item 。若没有此项内容 ，值为 0 。
	UINT32  class_data_off;		//指向class_data_item[]
	UINT32  static_value_off;	//指向 data 区里的一个list,格式为 encoded_array_item
};