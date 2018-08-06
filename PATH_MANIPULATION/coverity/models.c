extern "C" void __coverity_tainted_string_sink_content__(void *);
 
/*
  std::basic_filebuf<char, std::char_traits<char> >::__filebuf_type * std::basic_filebuf<char, std::char_traits<char> >::open(char const *, std::ios_base::openmode)
*/
void _ZNSt14basic_ifstreamIcSt11char_traitsIcEE4openEPKcSt13_Ios_Openmode(void *receiver, char const *filename) {
  __coverity_tainted_string_sink_content__(filename);
}
