/*============================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center (DKFZ)
All rights reserved.

Use of this source code is governed by a 3-clause BSD license that can be
found in the LICENSE file.

============================================================================*/

#ifndef mitkAutoSegmentationTool_h_Included
#define mitkAutoSegmentationTool_h_Included

#include "mitkCommon.h"
#include "mitkTool.h"
#include <MitkSegmentationExports.h>

namespace mitk
{
  class Image;

  /**
    \brief Superclass for tool that create a new segmentation without user interaction in render windows

    This class is undocumented. Ask the creator ($Author$) to supply useful comments.
  */
  class MITKSEGMENTATION_EXPORT AutoSegmentationTool : public Tool
  {
  public:
    mitkClassMacro(AutoSegmentationTool, Tool);

    /** This function controls wether a confirmed segmentation should replace the old
    * segmentation/working node (true) or if it should be stored as new and additional
    * node (false).
    */
    void SetOverwriteExistingSegmentation(bool overwrite);

    /**
     * @brief Gets the name of the currently selected segmentation node
     * @return the name of the segmentation node or an empty string if
     *         none is selected
     */
    std::string GetCurrentSegmentationName();

    /**
     * @brief Depending on the selected mode either returns the currently selected segmentation
     *        or creates a new one from the selected reference data and adds the new segmentation
     *        to the datastorage
     * @return a mitk::DataNode which contains a segmentation image
     */
    virtual mitk::DataNode *GetTargetSegmentationNode();

  protected:
    AutoSegmentationTool(); // purposely hidden
    ~AutoSegmentationTool() override;

    const char *GetGroup() const override;

    /** Helper that extracts the image for the passed timestep, if the image has multiple time steps.*/
    static Image::ConstPointer GetImageByTimeStep(const Image* image, unsigned int timestep);
    /** Helper that extracts the image for the passed time point, if the image has multiple time steps.*/
    static Image::ConstPointer GetImageByTimePoint(const Image* image, TimePointType timePoint);

    bool m_OverwriteExistingSegmentation;
  };

} // namespace

#endif
