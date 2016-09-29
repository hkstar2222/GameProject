#include "DbServer.h"
#include <stdio.h>
#include <afxsock.h>
#include "mysql.h"

using namespace std;

DbServer::DbServer()
{
	m_sql = new MYSQL();
}

DbServer::~DbServer()
{
	delete m_sql;
}

//初始化数据
int DbServer::ConnMySQL(char *host,char * port ,char * Db,char * user,char* passwd,char * charset,char * Msg)
{

	if (mysql_init((MYSQL*)m_sql) == NULL)
    {
        Msg = "inital mysql handle error";
        return 1;
    }

	if (mysql_real_connect((MYSQL*)m_sql, host, user, passwd, Db, 0, NULL, 0) == NULL)
    {
        Msg = "Failed to connect to database: Error";
        return 2;
    }

	if (mysql_set_character_set((MYSQL*)m_sql, charset) != 0)
    {
        Msg = "mysql_set_character_set Error";
        return 3;
    }
    return 0;
}

//查询数据
string DbServer::SelectData(char * SQL, char * Msg)
{
    MYSQL_ROW m_row;
    MYSQL_RES *result;
    char sql[2048];
    sprintf(sql,SQL);
    int rnum = 0;
    char rg = 0x20;//行隔开
    char cg = 0x20;//字段隔开

	if (mysql_query((MYSQL*)m_sql, sql) != 0)
    {
        Msg = "select ps_info Error";
        return "";
    }
	result = mysql_store_result((MYSQL*)m_sql);

	if (result == NULL)
    {
        Msg = "select username Error";
        return "";
    }
    string str("");
	while (m_row = mysql_fetch_row(result))
    {
		int cel = strlen(m_row[rnum]);
		for (int i = 0; i < cel; i++)
        {
                str += m_row[i];
                str += rg;
        }
        str += rg;
        rnum++;
    }

	mysql_free_result(result);

    return str;
}

//执行SQL语句
int DbServer::MySQL_Qyery(char * SQL, char * Msg)
{
    char sql[2048];
    sprintf(sql,SQL);
	if (mysql_query((MYSQL*)m_sql, sql) != 0)
    {
            Msg = "SSL Syntax Error";
            return 1;
    }
    return 0;
}


//关闭数据库连接
void DbServer::CloseMySQLConn()
{
	mysql_close((MYSQL*)m_sql);
}