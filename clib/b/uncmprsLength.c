/*
 * 小Y是一名负责处理文字信息的易信工程师，每天他都要和字符串打交道。为了提高存储
 * 和传输效率，小Y在课余时间经常会去研究字符串的存储方法。通过内部使用的一种统
 * 一的加密算法，所有的文字信息首先都会被转化成只包含大写字母['A'...'Z']的字符
 * 串。为了压缩这个加密后的字符串，小Y最近想出了两个存储的规则：
 *
 * (1)如果字符串中有连续相同的大写字母，它们可以选择用"字符+出现次数"的方式替代
 * 。如字符串'AABCCCCDD'，可以用'A2BC4D2'表示，也可以用'A2BC2C2DD'表示。
 *
 * (2)如果字符串中有连续出现的模式串(模式串长度大于1)，它们可以选择用"(模式)+出
 * 现次数"的方式替代。如字符串'FABCABCABCE'，可以用'F(ABC)3E'表示，也可以用
 * 'F(ABC)2ABCE'表示。
 *
 * 上述规则中的"连续"均指出现次数大于1，规则(2)中的括号后一定是一个大于1的数值
 * ，代表出现次数。综合上述两个规则，字符串'AABAABFAABAABFG'可以用'((A2B)2F)2G'
 * 表示。小Y保证输出的压缩串符合上述的两个规则，以下类型的非法字符串不会出现：
 * 
 * '(A)5': 括号冗余
 * 'A1A4': 数字1冗余
 * 'A((AA))2': 括号冗余
 * (ABC)1: 括号和数字1冗余
 *
 * 对于给定的一个用上述规则压缩后的字符串，对应的原串是唯一的。小Y想知道这个字
 * 符串原来的长度是多少，以此计算压缩倍率。你能帮助他吗？输入第一行是整数T(T <=
 * 100)，表示下面有T组数据。之后T行，每行为一组数据，每组数据为一个字符串。每个
 * 字符串只会包含26个大写字母['A'...'Z']，数字['0'...'9']和左右括号['(', ')']。
 * 保证输入数据一定合法，括号内的模式串长度一定大于1，表示出现次数的数字一定大
 * 于1，且字符串长度L <= 100。输出输出T行，每行对应一个数据的输出结果，表示字符
 * 串的实际长度。保证每个字符串展开后的长度不超过109。
 *
 * 样例输入
 * 4 
 * (AA)2A 
 * ((A2B)2)2G 
 * WANGYI 
 * A2BC4D2
 *
 * 样例输出
 * 5 
 * 13 
 * 6 
 * 9
 */
#ifndef __CLIB_B_UNCMPRSLENGTH_C__
#define __CLIB_B_UNCMPRSLENGTH_C__

typedef  unsigned int UINT;
UINT uncmprsLength(char *s)
{
    UINT i=0,count=0,repeat=0,isChar=0;
    UINT stack[100]={0}; // 足够大的 stack
    UINT stacktop=0;
    char c;
    while(c = s[i]){
        if( c == '(' ){
            stacktop++;
            stack[stacktop] = 0;
        }else if( c== ')' ){
            count = stack[stacktop];
            stacktop--;
            isChar = 0;
        }else if( c>= '0' && c<= '9'){
            repeat = 0;
            do{
                repeat = 10*repeat + (c-'0');
                i++; c = s[i];
            }while(c>='0'&&c<='9');
            i--;
            stack[stacktop] += repeat * count - isChar; 
        }else{
            stack[stacktop]++;
            count = 1;
            isChar = 1;
        }
        i++;
    }
    return stack[0];
}

#endif
