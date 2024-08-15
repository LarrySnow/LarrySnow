#include <stdio.h>

int inet_addr(const char* ip)
{
    int arr[4] = { 0 };  // ��ȷ�س�ʼ�������Դ洢4������
    int i = 0;
    int num = 0;

    while (*ip) 
    {
        if (*ip >= '0' && *ip <= '9') 
        {
            num = num * 10 + (*ip - '0');
        }
        else if (*ip == '.' || *ip == '\0') 
        {
            arr[i++] = num;
            num = 0;
            if (*ip == '\0')
            {
                break;
            }
        }
        ip++;
    }
    arr[i] = num;  // ���IP��ַ�����һ����

    // ת��Ϊ�����ֽ�˳��
    return (arr[3] << 24) | (arr[2] << 16) | (arr[1] << 8) | arr[0];
}

int main()
{
    char* ip = "192.168.1.11";
    int ret = inet_addr(ip);
    printf("0x%x\n", ret);  // ��ʮ�����Ƹ�ʽ��ӡ���
    return 0;
}
