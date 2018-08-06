extern "C" void __coverity_tainted_string_sink_content__(void *);
   
namespace std {
     template<typename _CharT> struct char_traits{
       };
     
       enum _Ios_Openmode {
           VAL1,
           VAL2
     };
     class ios_base {
         public:
         typedef _Ios_Openmode openmode;
         static _Ios_Openmode in;
     };
   
     template<typename _CharT, typename _Traits> class basic_istream {
     };
   
     template<typename _CharT, typename _Traits> class basic_ifstream : public basic_istream<_CharT, _Traits> {
   
         public:
         void open(char const * __s, ios_base::openmode __mode = ios_base::in) {
             __coverity_tainted_string_sink_content__((void *)__s);
         }
     };
}
   
template void std::basic_ifstream<char, std::char_traits<char> >::open(char const *, ios_base::openmode);
