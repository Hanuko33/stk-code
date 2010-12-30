// $Id$
//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2010 Lucas Baudin, Joerg Henrichs
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifdef ADDONS_MANAGER

#ifndef HEADER_ADDON_HPP
#define HEADER_ADDON_HPP

#include <string>

class XMLNode;

class Addon
{
public:
    std::string m_name;
    int         m_version;
    int         m_installed_version;
    std::string m_description;
    std::string m_icon;
    std::string m_file;
    std::string m_id;
    bool        m_installed;
    std::string m_type;
    Addon() {};
    /** Initialises the object from an XML node. */
    Addon(const XMLNode &xml, bool installed=false);
    // ------------------------------------------------------------------------
    /** Returns the name of the addon. */
    const std::string& getName() const {return m_name; }
    // ------------------------------------------------------------------------
    /** Returns the type of the addon. */
    const std::string& getType() const {return m_type; }
    // ------------------------------------------------------------------------
    /** Returns the filename of the addon. */
    const std::string& getFile() const {return m_file; }
    // ------------------------------------------------------------------------
    /** Returns the name of the icon of this addon. */
    const std::string& getIcon() const {return m_icon; }
    // ------------------------------------------------------------------------
    /** Returns the name of the addon. */
    const std::string& getDescription() const {return m_description; }
    // ------------------------------------------------------------------------
    /** Returns if the addon is installed. */
    bool  isInstalled() const {return m_installed; }
    // ------------------------------------------------------------------------
    /** Returns the installed version of an addon. */
    int   getInstalledVersion() const {return m_installed_version; }
    // ------------------------------------------------------------------------
    /** Returns the latest version of this addon. 
    *  m_version>m_installed_version if a newer version is available 
    *  online. */
    int   getVersion() const {return m_version; }
    // ------------------------------------------------------------------------
    /** Returns the ID of this addon. */
    const std::string& getId() const {return m_id; }
    // ------------------------------------------------------------------------
    /** True if this addon needs to be updated. */
    bool needsUpdate() const
    {
        return getInstalledVersion() < getVersion();
    }
    // ------------------------------------------------------------------------
    /** Marks this addon to be installed. If the addon is marked as being
     *  installed, it also updates the installed  version number to be the 
     *  same as currently available version number. */
    void setInstalled(bool state)
    {
        m_installed         = state;
        if(state)
            m_installed_version = m_version;
    }   // setInstalled
    // ------------------------------------------------------------------------
};   // Addon


#endif
#endif
