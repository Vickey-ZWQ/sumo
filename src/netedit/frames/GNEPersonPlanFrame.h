/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2019 German Aerospace Center (DLR) and others.
// This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v2.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v20.html
// SPDX-License-Identifier: EPL-2.0
/****************************************************************************/
/// @file    GNEPersonPlanFrame.h
/// @author  Pablo Alvarez Lopez
/// @date    Jun 2019
/// @version $Id$
///
// The Widget for add PersonPlan elements
/****************************************************************************/
#ifndef GNEPersonPlanFrame_h
#define GNEPersonPlanFrame_h


// ===========================================================================
// included modules
// ===========================================================================
#include "GNEFrame.h"


// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class GNEPersonPlanFrame
 */
class GNEPersonPlanFrame : public GNEFrame {

public:

    // ===========================================================================
    // class VTypeSelector
    // ===========================================================================

    class VTypeSelector : protected FXGroupBox {
        /// @brief FOX-declaration
        FXDECLARE(GNEPersonPlanFrame::VTypeSelector)

    public:
        /// @brief constructor
        VTypeSelector(GNEPersonPlanFrame* vehicleFrameParent);

        /// @brief destructor
        ~VTypeSelector();

        /// @brief get current type tag
        const GNEDemandElement* getCurrentPersonPlanType() const;

        /// @brief show VType selector
        void showVTypeSelector(const GNEAttributeCarrier::TagProperties& tagProperties);

        /// @brief hide VType selector
        void hideVTypeSelector();

        /// @brief refresh VType selector
        void refreshVTypeSelector();

        /// @name FOX-callbacks
        /// @{
        /// @brief Called when the user select another element in ComboBox
        long onCmdSelectVType(FXObject*, FXSelector, void*);
        /// @}

    protected:
        /// @brief FOX needs this
        VTypeSelector() {}

    private:
        /// @brief pointer to PersonPlan Frame Parent
        GNEPersonPlanFrame* myPersonPlanFrameParent;

        /// @brief comboBox with the list of elements type
        FXComboBox* myTypeMatchBox;

        /// @brief current vehicle type
        GNEDemandElement* myCurrentPersonPlanType;
    };

    // ===========================================================================
    // class HelpCreation
    // ===========================================================================

    class HelpCreation : protected FXGroupBox {

    public:
        /// @brief constructor
        HelpCreation(GNEPersonPlanFrame* vehicleFrameParent);

        /// @brief destructor
        ~HelpCreation();

        /// @brief show HelpCreation
        void showHelpCreation();

        /// @brief hide HelpCreation
        void hideHelpCreation();

        /// @brief update HelpCreation
        void updateHelpCreation();

    private:
        /// @brief pointer to PersonPlan Frame Parent
        GNEPersonPlanFrame* myPersonPlanFrameParent;

        /// @brief Label with creation information
        FXLabel* myInformationLabel;
    };

    // ===========================================================================
    // class TripRouteCreator
    // ===========================================================================

    class TripRouteCreator : protected FXGroupBox {
        /// @brief FOX-declaration
        FXDECLARE(GNEPersonPlanFrame::TripRouteCreator)

    public:
        /// @brief default constructor
        TripRouteCreator(GNEPersonPlanFrame* vehicleFrameParent);

        /// @brief destructor
        ~TripRouteCreator();

        /// @brief show TripRouteCreator
        void showTripRouteCreator();

        /// @brief show TripRouteCreator
        void hideTripRouteCreator();

        /// @brief check if from and to edges create a valid route
        bool isValid(SUMOVehicleClass vehicleClass) const;

        /// @brief get current selected edgesm
        std::vector<GNEEdge*> getSelectedEdges() const;

        /// @brief set edge from (and change color)
        void addEdge(GNEEdge* edge);

        /// @brief clear edges (and restore colors)
        void clearEdges();

        /// @brief draw temporal route
        void drawTemporalRoute() const;

        /// @name FOX-callbacks
        /// @{
        /// @brief Called when the user click over button "Abort route creation"
        long onCmdAbortRouteCreation(FXObject*, FXSelector, void*);

        /// @brief Called when the user click over button "Finish route creation"
        long onCmdFinishRouteCreation(FXObject*, FXSelector, void*);

        /// @brief Called when the user click over button "Remove las inserted edge"
        long onCmdRemoveLastRouteEdge(FXObject*, FXSelector, void*);
        /// @}

    protected:
        /// @brief FOX needs this
        TripRouteCreator() {}

    private:
        /// @brief pointer to PersonPlan Frame Parent
        GNEPersonPlanFrame* myPersonPlanFrameParent;

        /// @brief current selected edges
        std::vector<GNEEdge*> mySelectedEdges;

        /// @brief vector with temporal route edges
        std::vector<GNEEdge*> myTemporalRoute;

        /// @brief button for finish route creation
        FXButton* myFinishCreationButton;

        /// @brief button for abort route creation
        FXButton* myAbortCreationButton;

        /// @brief button for removing last inserted edge
        FXButton* myRemoveLastInsertedEdge;
    };

    /**@brief Constructor
     * @brief parent FXHorizontalFrame in which this GNEFrame is placed
     * @brief viewNet viewNet that uses this GNEFrame
     */
    GNEPersonPlanFrame(FXHorizontalFrame* horizontalFrameParent, GNEViewNet* viewNet);

    /// @brief Destructor
    ~GNEPersonPlanFrame();

    /// @brief show Frame
    void show();

    /**@brief add vehicle element
     * @param objectsUnderCursor collection of objects under cursor after click over view
     * @return true if vehicle was sucesfully added
     */
    bool addPersonPlan(const GNEViewNetHelper::ObjectsUnderCursor& objectsUnderCursor);

    /// @brief get TripRouteCreator modul
    TripRouteCreator* getTripRouteCreator() const;

protected:
    /// @brief enable moduls depending of item selected in ItemSelector
    void enableModuls(const GNEAttributeCarrier::TagProperties& tagProperties);

    /// @brief disable moduls if element selected in itemSelector isn't valid
    void disableModuls();

private:
    /// @brief item selector (used to select diffent kind of vehicles)
    ItemSelector* myItemSelector;

    /// @brief PersonPlan Type selectors
    VTypeSelector* myVTypeSelector;

    /// @brief internal vehicle attributes
    AttributesCreator* myPersonPlanAttributes;

    /// @brief TripRouteCreator
    TripRouteCreator* myTripRouteCreator;

    /// @brief Help creation
    HelpCreation* myHelpCreation;
};


#endif

/****************************************************************************/
