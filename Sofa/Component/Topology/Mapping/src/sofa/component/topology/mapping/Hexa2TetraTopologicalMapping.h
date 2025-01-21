/******************************************************************************
*                 SOFA, Simulation Open-Framework Architecture                *
*                    (c) 2006 INRIA, USTL, UJF, CNRS, MGH                     *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#pragma once
#include <sofa/component/topology/mapping/config.h>

#include <sofa/core/topology/TopologicalMapping.h>

#include <sofa/type/Vec.h>
#include <map>

#include <sofa/core/BaseMapping.h>

#include <sofa/core/objectmodel/lifecycle/RenamedData.h>


namespace sofa::component::topology::mapping
{


/**
* This class, called Hexa2TetraTopologicalMapping, is a specific implementation of the interface TopologicalMapping where :
*
* INPUT TOPOLOGY = HexahedronSetTopology
* OUTPUT TOPOLOGY = TetrahedronSetTopology
*
* Tetra2TriangleTopologicalMapping class is templated by the pair (INPUT TOPOLOGY, OUTPUT TOPOLOGY)
*
*/

class SOFA_COMPONENT_TOPOLOGY_MAPPING_API Hexa2TetraTopologicalMapping : public sofa::core::topology::TopologicalMapping
{
public:
    SOFA_CLASS(Hexa2TetraTopologicalMapping,sofa::core::topology::TopologicalMapping);
protected:
    /** \brief Constructor.
    *
    */
    Hexa2TetraTopologicalMapping();

    /** \brief Destructor.
    *
    * Does nothing.
    */
    ~Hexa2TetraTopologicalMapping() override;
public:
    /** \brief Initializes the target BaseTopology from the source BaseTopology.
    */
    void init() override;


    /** \brief Translates the TopologyChange objects from the source to the target.
    *
    * Translates each of the TopologyChange objects waiting in the source list so that they have a meaning and
    * reflect the effects of the first topology changes on the second topology.
    *
    */
    void updateTopologicalMappingTopDown() override;

    Index getFromIndex(Index ind) override;
    SOFA_ATTRIBUTE_DEPRECATED__RENAME_DATA()
    sofa::core::objectmodel::lifecycle::RenamedData<bool> swapping;

    sofa::core::objectmodel::Data<bool> d_swapping; ///< Boolean enabling to swapp hexa-edges  in order to avoid bias effect

};

} //namespace sofa::component::topology::mapping
