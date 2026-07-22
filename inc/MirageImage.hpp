/**
 * @file MirageImage.hpp
 * @author BambooSlips
 * @brief 
 * @version 0.1
 * @date 2024-11-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "common_def.hpp"
#include "MirageModel.hpp"
#include "MirageObject.hpp"
#include <memory>

namespace Mirage
{
   class MIRAGE_API Image: public Model {
      public:
         Image();
         virtual ~Image();

         /**
          * @brief Set the layer the image belongs to 
          * 
          * @param uLayer layer code to be set
          */
         virtual void SetLayer(unsigned char uLayer) override;

         /**
          * @brief Get the layer the image belongs to
          * 
          * @return unsigned char 
          */
         virtual unsigned char GetLayer() override;

         /**
          * @brief Set the image material
          * 
          * @param svMaterial image material to be set
          */
         virtual void SetMaterial(std::string_view svMaterial);

         /**
          * @brief Fill with a gradually changing color if it's blank
          * 
          * @param rColors color to be used
          */
         virtual void FillColor(const std::vector<vec4<float>>& rColors);

         /**
          * @brief Fill with a pure color if it's blank
          * 
          * @param rColor color to be used
          */
         virtual void FillColor(const vec4<float>& rColor);

         /**
          * @brief Set the image size
          * 
          * @param fWidth width of the image
          * @param fHeight height of the image
          */
         virtual void SetSize(float fWidth, float fHeight);

         /**
          * @brief Set the scale of the image
          * 
          * @param rScale scale to be set
          */
         virtual void SetScale(const Mirage::vec3<float>& rScale) override;

         /**
          * @brief Set the position of the image
          * 
          * @param rPosition position to be set
          * @param bOnOverlay on overlay or not
          */
         virtual void SetPosition(
            const Mirage::vec3<float>& rPosition,
            bool                       bOnOverlay = false
         ) override;

         // /**
         //  * @brief 
         //  * 
         //  * @param fnTrigger event trigger
         //  * @param fnAction  event action
         //  * @return unsigned long 
         //  */
         // virtual unsigned long AddEvent(
         //    std::function<bool()> fnTrigger,
         //    std::function<void()> fnAction
         // );

         /**
          * @brief Configure the image
          * 
          * @param nWidth     width of the image
          * @param nHeight    height of the image
          * @param uLayer     layer code
          * @param svMaterial image material
          */
         virtual void Configure(
            int                        nWidth,
            int                        nHeight,
            unsigned char              uLayer,
            std::string_view           svMaterial
         );

         /**
          * @brief Add a mask to the image 
          * 
          * @param svMaterial material of the mask
          * @param bEnable    enable the mask or not
          */
         virtual void AddMask(std::string_view svMaterial, bool bEnable = false);

         /**
          * @brief Is the image mask enabled or not 
          * 
          * @return true
          * @return false 
          */
         virtual bool IsMaskEnabled();

         /**
          * @brief Disable the image mask 
          * 
          */
         virtual void DisableMask();

         /**
          * @brief Enable the image mask 
          * 
          */
         virtual void EnableMask();

         /**
          * @brief Set the Mask Status object
          * 
          * @param bEnable 
          */
         virtual void SetMaskStatus(bool bEnable);

         /**
          * @brief Is depth enabled 
          * 
          * @return true 
          * @return false 
          */
         virtual bool IsDepthEnabled();

         /**
          * @brief Set the depth status
          * 
          * @param bEnable enable or not
          */
         virtual void SetDepthStatus(bool bEnable);

         /**
          * @brief Refresh the image 
          * 
          */
         virtual void Refresh() override;
      
      private:
         virtual void Render() override;

      private:
         float                                 m_fWidth; 
         float                                 m_fHeight; 
         float                                 m_fViewWidth;
         float                                 m_fViewHeight;
         bool                                  m_bOnOverlay;
         bool                                  m_bMaskEnabled;
         Mirage::vec3<float>                   m_vPosition;
         Mirage::vec3<float>                   m_vScale;
         std::unique_ptr<Mirage::MeshRenderer> m_upMaskRenderer;

   }; 
} // namespace Mirage
