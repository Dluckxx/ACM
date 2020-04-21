/*

    1.名字：   determinant.c

    2.功能：   求解n阶行列式值

    3.编者：   HeavenMo <1621326181@qq.com>

    4.时间：   2015-10-2 22:42

    5.叙述：   递归法实现n阶行列式的求解

    6.申明：   Win 8.1 pro / GCC 4.8.1编译器亲测通过

    7.结构：
                a)main函数部分完成行列式的输入操作

                b)det函数完成行列式的值的返回

                c)det函数中，将原来的n阶行列式不断的递归分解，

                如，n阶矩阵分解为n个(n-1)阶余子矩阵，(n-1)阶分解成(n-1)个(n-2)阶余子矩阵，

                ...，以此类推

                d)递归至2阶时，计算2阶行列式的值，并返回给上一层，...，

                以此类推

*/

//有关头文件的包含，因为要用到动态内存的分配，所以包含stdlib.h
#include <stdio.h>

#include <stdlib.h>

//定制数据类型，方便修改
typedef int data_type;

typedef unsigned int uint;

//计算n阶行列式的函数声明
data_type det(data_type *p, uint n);

int main(void) {
    //n为行列式的阶数，i，n，m为非负值，所以定义为uint
    uint i, n, m;

    //提示输入行列式的阶数
    printf("请输入行列式的阶数:\n");
    scanf("%u", &n);
    m = n * n;

    //程序的关键所在，将n阶行列式看成是一个长度是n*n的一维数组，m为数组的长度
    data_type *p = (data_type *) calloc(m, sizeof(data_type));

    printf("请输入行列式的元素值:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", p + i);
    }

    printf("\n所求行列式的值 = %d\n", det(p, n));

    //释放相应的内存
    free(p);
    return 0;
}

//p指向长度为n*n的数组，n为行列式的阶数
data_type det(data_type *p, uint n) {
    //n = 1时的情况
    if (n == 1) {
        return *p;
    }

    //递归基准
    if (n == 2) {
        return ((*p) * (*(p + 3)) - (*(p + 1)) * (*(p + 2)));
    }

    //m1:当前行列式的元素个数，m2：分解后的行列式的元素个数
    uint i, j, k, m1, m2;
    m1 = n * n;
    m2 = (n - 1) * (n - 1);

    //为分配后的n个n-1阶的行列式分配内存的基址
    data_type *p_list[n];
    for (i = 0; i < n; i++) {
        p_list[i] = (data_type *) calloc(m2, sizeof(data_type));
    }

    //关键一步，筛选出代数余子矩阵，i(0 - n-1)：原矩阵可以分解为n个n-1阶代数余子矩阵
    for (i = 0; i < n; i++) {
        //j = n意为筛选元素要从第二行开始，k变量统计代数余子矩阵的元素个数
        for (j = n, k = 0; j < m1; j++) {
            //考察原矩阵与余子矩阵的关系，构造余子矩阵
            if (j % n != i) {
                *(p_list[i] + k) = *(p + j);
                k++;
            }
        }
    }

    //根据递推公式求和，sign为代数余子式的符号，与行数(其实是第一行)，列数有关
    int sign = -1;
    data_type sum = 0;
    for (i = 0; i < n; i++) {
        sign *= -1;

        //调用函数，通过对第一行的各元素与相应的代数余子矩阵的行列式值之积求和，实现递归求值
        sum += sign * (*(p + i)) * det(p_list[i], n - 1);
    }

    //返回函数值
    return sum;
}