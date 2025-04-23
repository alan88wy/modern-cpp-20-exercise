
import std;

using namespace std;

int main()
{
    char fixb[] {"11 2.222 Hello"}; 
    ispanstream  stream{ span<char> { fixb } };

    int i;
    double d;
    string str;
    
    stream >> i >> d >> str;

    println("Parsed data: int: {}, double: {}, string: {}", i, d, str);

    char fixedBuffer[32]{};
    ospanstream ostream{span{fixedBuffer}};
    ostream << "Hello " << 2.222 << ' ' << 11;
    println("Buffer contents: \"{}\"", fixedBuffer);
}