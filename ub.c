#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;
typedef unsigned int DWORD;
#define ERROR_UNKNOWN 1
#define ERROR_SUCCESS 0

typedef struct
{
    BYTE* pFlag;
    BYTE* pData;                      /* 数据指针 */
    DWORD dwUBSize;                   /* UB 尺寸 */
    DWORD dwTotalCnt, dwReserveCnt;        /* 总数, 可用数 */
    DWORD* pIndex;
    DWORD dwCurIndex;                     /* 当前指针 */
    DWORD* pReserveIndex;               /* 可用索引队列 */
    DWORD dwMaxUsed;             /* 最大使用个数，这个值除非清零，否则不会减小(流程数据区优化，chenly) */
} T_RCP_UB_POOL;

BYTE* RCPUBPoolGetUBWithIndex(T_RCP_UB_POOL* ptUBPool, DWORD* pdwIndex)
{
    BYTE* ptUB = NULL;
    DWORD dwDataIndex = 0;

    /* 空间大小判断 */
    if(ptUBPool->dwReserveCnt == 0)
    {
        return NULL;
    }

    /* 从资源索引获取数据存放位置 */
    dwDataIndex = ptUBPool->pReserveIndex[ptUBPool->dwCurIndex];
    ptUB = ptUBPool->pData + (dwDataIndex * ptUBPool->dwUBSize);
    *pdwIndex = dwDataIndex;
    /* 设置占用标志 */
    ptUBPool->pFlag[dwDataIndex]  = 1;
    /* 索引自增 */
    ptUBPool->dwCurIndex = (ptUBPool->dwCurIndex + 1) % ptUBPool->dwTotalCnt;
    ptUBPool->dwReserveCnt--;
    return ptUB;
}
DWORD RCPUBPoolRetUBByIndex(T_RCP_UB_POOL* ptUBPool, DWORD dwIndex)
{
    /* 索引有效性判断 */
    if(dwIndex >= ptUBPool->dwTotalCnt || ptUBPool->dwReserveCnt >= ptUBPool->dwTotalCnt)
    {
        return ERROR_UNKNOWN;
    }

    /* 占用标志判断 */
    if(ptUBPool->pFlag[dwIndex] != 0)
    {
        /* 将索引放入索引队列尾部 */
        ptUBPool->pIndex[dwIndex] = (ptUBPool->dwCurIndex + ptUBPool->dwReserveCnt) % ptUBPool->dwTotalCnt;
        ptUBPool->pReserveIndex[ptUBPool->pIndex[dwIndex]] = dwIndex;
        ptUBPool->dwReserveCnt++;
        /* 重新初始化 */
        ptUBPool->pFlag[dwIndex] = 0;
    }

    return ERROR_SUCCESS;
}

DWORD RCPUBPoolCreate(T_RCP_UB_POOL* ptUBPool, DWORD dwUBSize, DWORD dwCnt)
{
    DWORD i = 0;

    if(ptUBPool == NULL)
        return ERROR_UNKNOWN;

    /* 数据区内存分配 */
    ptUBPool->pFlag = malloc(dwCnt);

    if(ptUBPool->pFlag == NULL)
    {
        return ERROR_UNKNOWN;
    }

    memset(ptUBPool->pFlag, 0, dwCnt);
    ptUBPool->pData = malloc(dwCnt * dwUBSize); /*分配时会自动按照系统字节对齐*/

    if(ptUBPool->pData == NULL)
        {
        free(ptUBPool->pFlag);
        ptUBPool->pFlag = NULL;
        return ERROR_UNKNOWN;
    }

    memset(ptUBPool->pData, 0, dwCnt * dwUBSize);
    /* 索引区内存分配 */
    ptUBPool->pReserveIndex = (DWORD*) malloc(sizeof(DWORD) * dwCnt + sizeof(DWORD) * dwCnt);

    if(ptUBPool->pReserveIndex == NULL)
    {
        free(ptUBPool->pFlag);
        ptUBPool->pFlag = NULL;
        free(ptUBPool->pData);
        ptUBPool->pData = NULL;
        return ERROR_UNKNOWN;
    }

    ptUBPool->pIndex = ptUBPool->pReserveIndex + dwCnt;
    /* 变量初始化 */
    ptUBPool->dwUBSize = dwUBSize;
    ptUBPool->dwReserveCnt = dwCnt;
    ptUBPool->dwTotalCnt = dwCnt;
    ptUBPool->dwCurIndex = 0;

    /* 可用索引初始化 */
    for(i = 0; i < ptUBPool->dwTotalCnt; i++)
    {
        ptUBPool->pIndex[i] = i;
        ptUBPool->pReserveIndex[i] = i;
    }

    return ERROR_SUCCESS;
}

int main()
{
    T_RCP_UB_POOL* ptUbPool = malloc(sizeof(T_RCP_UB_POOL));
    RCPUBPoolCreate(ptUbPool, 100, 10);
    return 0;
}
