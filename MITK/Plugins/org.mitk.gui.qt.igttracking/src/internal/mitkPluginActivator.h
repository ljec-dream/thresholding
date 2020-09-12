/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/


#ifndef MITKPLUGINACTIVATORIGT_H
#define MITKPLUGINACTIVATORIGT_H

#include <ctkPluginActivator.h>

namespace mitk {

class PluginActivator :
  public QObject, public ctkPluginActivator
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org_mitk_gui_qt_igttracking")
  Q_INTERFACES(ctkPluginActivator)

public:

  void start(ctkPluginContext* context) override;
  void stop(ctkPluginContext* context) override;

  static ctkPluginContext* GetContext();

private:
  static ctkPluginContext* m_Context;


}; // PluginActivator

}

#endif // MITKPLUGINACTIVATORIGT_H
