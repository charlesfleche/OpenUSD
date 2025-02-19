//
// Copyright 2023 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/* **                                                                      ** */
/* ** This file is generated by a script.                                  ** */
/* **                                                                      ** */
/* ** Do not edit it directly (unless it is within a CUSTOM CODE section)! ** */
/* ** Edit hdSchemaDefs.py instead to make changes.                        ** */
/* **                                                                      ** */
/* ************************************************************************** */

#include "hdPrman/rileyLightShaderSchema.h"

#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/base/trace/trace.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdPrmanRileyLightShaderSchemaTokens,
    HD_PRMAN_RILEY_LIGHT_SHADER_SCHEMA_TOKENS);

// --(BEGIN CUSTOM CODE: Schema Methods)--
// --(END CUSTOM CODE: Schema Methods)--

HdPrmanRileyShadingNodeVectorSchema
HdPrmanRileyLightShaderSchema::GetLight()
#if HD_API_VERSION >= 66
                                            const
#else
                                                 
#endif
{
    return HdPrmanRileyShadingNodeVectorSchema(_GetTypedDataSource<HdVectorDataSource>(
        HdPrmanRileyLightShaderSchemaTokens->light));
}

HdPrmanRileyShadingNodeVectorSchema
HdPrmanRileyLightShaderSchema::GetLightFilter()
#if HD_API_VERSION >= 66
                                            const
#else
                                                 
#endif
{
    return HdPrmanRileyShadingNodeVectorSchema(_GetTypedDataSource<HdVectorDataSource>(
        HdPrmanRileyLightShaderSchemaTokens->lightFilter));
}

/*static*/
HdContainerDataSourceHandle
HdPrmanRileyLightShaderSchema::BuildRetained(
        const HdVectorDataSourceHandle &light,
        const HdVectorDataSourceHandle &lightFilter
)
{
    TfToken _names[2];
    HdDataSourceBaseHandle _values[2];

    size_t _count = 0;

    if (light) {
        _names[_count] = HdPrmanRileyLightShaderSchemaTokens->light;
        _values[_count++] = light;
    }

    if (lightFilter) {
        _names[_count] = HdPrmanRileyLightShaderSchemaTokens->lightFilter;
        _values[_count++] = lightFilter;
    }
    return HdRetainedContainerDataSource::New(_count, _names, _values);
}

HdPrmanRileyLightShaderSchema::Builder &
HdPrmanRileyLightShaderSchema::Builder::SetLight(
    const HdVectorDataSourceHandle &light)
{
    _light = light;
    return *this;
}

HdPrmanRileyLightShaderSchema::Builder &
HdPrmanRileyLightShaderSchema::Builder::SetLightFilter(
    const HdVectorDataSourceHandle &lightFilter)
{
    _lightFilter = lightFilter;
    return *this;
}

HdContainerDataSourceHandle
HdPrmanRileyLightShaderSchema::Builder::Build()
{
    return HdPrmanRileyLightShaderSchema::BuildRetained(
        _light,
        _lightFilter
    );
}

/*static*/
HdPrmanRileyLightShaderSchema
HdPrmanRileyLightShaderSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer)
{
    return HdPrmanRileyLightShaderSchema(
        fromParentContainer
        ? HdContainerDataSource::Cast(fromParentContainer->Get(
                HdPrmanRileyLightShaderSchemaTokens->rileyLightShader))
        : nullptr);
}

/*static*/
const TfToken &
HdPrmanRileyLightShaderSchema::GetSchemaToken()
{
    return HdPrmanRileyLightShaderSchemaTokens->rileyLightShader;
}

/*static*/
const HdDataSourceLocator &
HdPrmanRileyLightShaderSchema::GetDefaultLocator()
{
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

/* static */
const HdDataSourceLocator &
HdPrmanRileyLightShaderSchema::GetLightLocator()
{
    static const HdDataSourceLocator locator =
        GetDefaultLocator().Append(
            HdPrmanRileyLightShaderSchemaTokens->light);
    return locator;
}

/* static */
const HdDataSourceLocator &
HdPrmanRileyLightShaderSchema::GetLightFilterLocator()
{
    static const HdDataSourceLocator locator =
        GetDefaultLocator().Append(
            HdPrmanRileyLightShaderSchemaTokens->lightFilter);
    return locator;
} 

PXR_NAMESPACE_CLOSE_SCOPE