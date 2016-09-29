#include "FuncDef.h"
#include "DbServer.h"

_INT TEST_FUNC::testDbServer()
{

	DbServer* db = new DbServer();

	char* host = "127.0.0.1";
	char* user = "root";
	char* port = "3306";
	char* passwd = "123456";
	char* dbname = "test-sql";
	char* charset = "UTF8";//支持中文
	char* Msg = "test msg";//消息变量

	printf("%d  \n", db->ConnMySQL(host, port, dbname, user, passwd, charset, Msg));

	if (db->ConnMySQL(host, port, dbname, user, passwd, charset, Msg) == 0)
		printf("连接成功\n");
	else
	{
		printf(Msg);
		printf("xxxxxxxxxxxxxxxxxxxxxxd?\n");
	}
	char* SQL = "";

	
	//if (str.length() > 0)
	//{
	//	printf("查询成功/r/n");
	//	printf("/r/n");
	//}
	//else
	//{
	//	printf(Msg);
	//}

	//SQL = "INSERT INTO t1 (i) VALUES(1);";
	SQL = "SELECT id,v FROM t";
	std::string str = db->SelectData(SQL,Msg);

	/*int x = db->MySQL_Qyery(SQL, Msg);
	printf("---------  \n   %s \n", &x)*/;

	if (str.length() >= 0)
	{
		printf("插入成功\n");
		printf( str.c_str());

		printf("\n\n\n  %s", Msg);
	}
 	else
	{
		printf("插入失败\n");
		printf(Msg);
	}

	//SQL = "update vcaccesstest set username = '修改了',passwd='2345' where ids = 3 ";
	//if (db->UpdateData(SQL, Msg) == 0)
	//	printf("更新成功/r/n");
	//

		

	return TEST_RET::SUCCESS;
}
