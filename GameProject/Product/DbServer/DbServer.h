#ifndef _DB_SERVER_H_
#define _DB_SERVER_H_

#include "BaseDef.h"
#include <string>

class DbServer
{
public:
	DLL_API DbServer();
	DLL_API ~DbServer();
   /*
   主要的功能：
   初始化数据库
   连接数据库
   设置字符集

   入口参数：
   host ：服务器IP
   port:数据库端口
   Db：数据库名称
   user：数据库用户
   passwd：数据库用户的密码
   charset：希望使用的字符集
   Msg:返回的消息，包括错误消息

   出口参数：
   int ：0表示成功；1表示失败
   */
	DLL_API int ConnMySQL(char *host, char * port, char * Db, char * user, char* passwd, char * charset, char * Msg);

   /*
   主要的功能：
   查询数据

   入口参数：
   SQL：查询的SQL语句
   Msg:返回的消息，包括错误消息

   出口参数：
   string 准备放置返回的数据，多条记录则用0x20隔开,多个栏位用0x20隔开
   如果 返回的长度＝ 0，则表示无结果
   */
	DLL_API std::string SelectData(char * SQL, char * Msg);

   /*
   主要功能：
   执行指定sql语句

   入口参数
   SQL：查询的SQL语句
   Msg:返回的消息，包括错误消息

   出口参数：
   int ：0表示成功；1表示失败
   */
	DLL_API int MySQL_Qyery(char * SQL, char * Msg);

   /*
   主要功能：
   关闭数据库连接
   */
	DLL_API void CloseMySQLConn();

private:
	/*
	参数
	*/
	void*	m_sql;
};

#endif	//_DB_SERVER_H_