#include <stdio.h>

void print_it() {
  // TODO
  printf("Bit operations are fun!\n");
}

void print_int() {
  // TODO
    int x = 10;
    int y = 13;

    printf("x = %d\n",x);
    printf("y = %d\n",y);
    printf("size of signed int in bytes is %ld.\n",sizeof(x));
    printf("size of signed int in bits is %ld.\n",8*sizeof(x));
    printf("%d + %d = %d.\n",x,y,x+y);
}

void print_float() {
  // TODO
    float x =10;
    float y=13;
    float floatType;
    
    
    printf("x = %lf\n",x);
    printf("y = %lf\n",y);
    printf("size of single float in bytes is %1d.\n",sizeof(floatType));
    printf("size of single float in bits is %1d.\n",sizeof(floatType)*8);
    printf("%lf + %lf = %lf.\n",x,y,x+y);
    printf("%lf + %lf = %d.\n",x,y,(int)(x+y));
}

void print_char() {
  // TODO
    char c = 'C';
    char a = 65;
    char f = 'F';
    char e = 'E';
    char b = 'B';
    
    
    printf("c = %C\n", c);
    printf("a = %C\n", a);
    printf("%C%C%C%C%C%C%C%C\n",c,a,f,e,b,a,b,e);
    printf("number of bytes: %d.\n",sizeof("CAFEBABE"));}

void packing_bytes() {
  // TODO
    unsigned char b3 = 202;
    unsigned char b2 = 254;
    unsigned char b1 = 186;
    unsigned char b0 = 190;
    unsigned int u,u0,u1,u2,u3;
    
    u3 = b3 << 24;
    u2 = b2 << 16;
    u1 = b1 << 8;
    u0 = b0;
    u = u3 | u2 | u1 | u0;
    printf("%X\n",u);
}

void unpacking_bytes() {
  // TODO
    unsigned int i1 = 1835098984u;
    unsigned int i2 = 1768842611u;
    unsigned char c1,c2,c3,c4,c5,c6,c7,c8;
    
    
    c1 = i1 >> 24;
    c2 = (i1 << 8) >> 24;
    c3 = (i1 << 16) >> 24;
    c4 = (i1 << 24) >> 24;
    c5 = i2 >> 24;
    c6 = (i2 << 8) >> 24;
    c7 = (i2 << 16) >> 24;
    c8 = (i2 << 24) >> 24;
    
    printf("%c%c%c%c%c%c%c%c\n",c1,c2,c3,c4,c5,c6,c7,c8);
}

void print_bits() {
  // TODO
    unsigned char a = 181;
    signed char b = -75;
    
    for (int i = 0; i<=7; i++){
        printf("%d",( a & (1 << (7-i)) ) >> (7-i));
    }
    
    printf("\n");
    
    for (int i=0; i<=7; i++){
        printf("%d",( b & (1 << (7-i)) ) >> (7-i));
    }
    
    printf("\n");
    
}

void extracting_fields() {
  // TODO
    unsigned int a = 0xCAFEBABE;
    int u0,u1,u2,u3,u4,u5,u6,u7,u8,u9;
    u0=a>>29;
    u1=(a<<3)>>28;
    u2=(a<<7)>>28;
    u3=(a<<11)>>29;
    u4=(a<<14)>>29;
    u5=(a<<17)>>28;
    u6=(a<<21)>>28;
    u7=(a<<25)>>29;
    u8=(a<<28)>>30;
    u9=(a<<30)>>30;
    printf("%d %d %d %d %d %d %d %d %d %d\n",u0,u1,u2,u3,u4,u5,u6,u7,u8,u9);
}

void updating_fields() {
  // TODO
    unsigned int a = ((1<<4)-1)<<18;
    unsigned int b = ((1<<5)-1)<<10;
    unsigned int c,d,e,x,q,w;
    unsigned int f = 17512807u;
    
    c = (a|b);
    d = ((~c)&f);
    e = 8<<18;
    x = 17<<10;
    q = (e|x);
    w = (d|q);
    
    printf("%08x\n",w);

}
