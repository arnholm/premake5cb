#include <sdk.h> // Code::Blocks SDK
#include <fstream>
#include <configurationpanel.h>
#include "premake5cb.h"
#include "pm_workspace_cb.h"

// Register the plugin with Code::Blocks.
// We are using an anonymous namespace so we don't litter the global one.
namespace
{
    PluginRegistrant<premake5cb> reg(_T("premake5cb"));
}



// constructor
premake5cb::premake5cb()
{
    // Make sure our resources are available.
    // In the generated boilerplate code we have no resources but when
    // we add some, it will be nice that this code is in place already ;)
    if(!Manager::LoadResource(_T("premake5cb.zip")))
    {
        NotifyMissingFile(_T("premake5cb.zip"));
    }
}

// destructor
premake5cb::~premake5cb()
{
}

void premake5cb::OnAttach()
{
    // do whatever initialization you need for your plugin
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be TRUE...
    // You should check for it in other functions, because if it
    // is FALSE, it means that the application did *not* "load"
    // (see: does not need) this plugin...

    // we save the premak5 file after compile completed
    Manager::Get()->RegisterEventSink(cbEVT_COMPILER_FINISHED , new cbEventFunctor<premake5cb, CodeBlocksEvent>(this, &premake5cb::OnSave));

}

void premake5cb::OnRelease(bool appShutDown)
{
    // do de-initialization for your plugin
    // if appShutDown is true, the plugin is unloaded because Code::Blocks is being shut down,
    // which means you must not use any of the SDK Managers
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be FALSE...
}


void premake5cb::OnSave(CodeBlocksEvent& event)
{
   if(m_IsAttached) {
      auto ws = std::make_shared<pm_workspace_cb>();
      wxFileName lua_name(ws->filename().GetPath(),"premake5","lua");

      std::string fname = lua_name.GetFullPath().ToStdString();
      std::ofstream out(fname);
      if(out.is_open()) {
         ws->premake_export(out);
      }
   }
}
