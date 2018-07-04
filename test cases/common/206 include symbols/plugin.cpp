#if defined _WIN32 || defined __CYGWIN__
  #define DLL_IMPORT __declspec(dllimport)
#else
  #define DLL_IMPORT
#endif

#if defined _WIN32 || defined __CYGWIN__
  #define DLL_PUBLIC __declspec(dllexport)
#else
  #if defined __GNUC__
    #define DLL_PUBLIC __attribute__ ((visibility("default")))
  #else
    #pragma message ("Compiler does not support symbol visibility.")
    #define DLL_PUBLIC
  #endif
#endif

// this is defined in the registry library
extern bool DLL_IMPORT plugin_was_loaded;

struct plugin_registrator_t {
    plugin_registrator_t() {
      plugin_was_loaded = true; // this will run on library initialization, when it is loaded
    }
} reg;

extern "C" { // to avoid C++ name mangling
  void DLL_PUBLIC plugin_dummy() { }
}