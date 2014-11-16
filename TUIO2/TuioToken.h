/*
 TUIO2 C++ Library
 Copyright (c) 2009-2014 Martin Kaltenbrunner <martin@tuio.org>
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 3.0 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library.
*/

#ifndef INCLUDED_TUIOTOKEN_H
#define INCLUDED_TUIOTOKEN_H

#include "TuioComponent.h"

namespace TUIO2 {
	
	/**
	 * The TuioToken class encapsulates /tuio2/tok TUIO tokens.
	 *
	 * @author Martin Kaltenbrunner
	 * @version 2.0.a0
	 */ 
	class LIBDECL TuioToken: public TuioComponent {
		
	protected:
		/**
		 * The individual symbol ID number that is assigned to each TuioToken.
		 */ 
		int symbol_id;
        /**
        * The symbol type ID that is assigned to each TuioToken.
        */
        short type_id;
        /**
         * The user ID that is assigned to each TuioToken.
         */
        short user_id;
		
	public:
		using TuioComponent::update;
		
		/**
		 * This constructor takes a TuioTime argument and assigns it along with the provided 
		 * Session ID, Symbol ID, X and Y coordinate and angle to the newly created TuioToken.
		 *
		 * @param	ttime	the TuioTime to assign
		 * @param	si	the Session ID to assign
         * @param	ti	the Type ID  to assign
         * @param	ui	the User ID  to assign
		 * @param	sym	the Symbol ID  to assign
		 * @param	xp	the X coordinate to assign
		 * @param	yp	the Y coordinate to assign
		 * @param	a	the angle to assign
		 */
		TuioToken (TuioTime ttime, int si, short ti, short ui, int sym, float xp, float yp, float a);

		/**
		 * This constructor takes the provided Session ID, Symbol ID, X and Y coordinate
		 * and angle, and assigs these values to the newly created TuioToken.
		 *
		 * @param	si	the Session ID to assign
         * @param	ti	the Type ID  to assign
         * @param	ui	the User ID  to assign
		 * @param	sym	the Symbol ID  to assign
		 * @param	xp	the X coordinate to assign
		 * @param	yp	the Y coordinate to assign
		 * @param	a	the angle to assign
		 */	
		TuioToken (int si, short ti, short ui, int sym, float xp, float yp, float a);
        
        /**
         * This constructor takes the provided Session ID, Symbol ID, X and Y coordinate
         * and angle, and assigs these values to the newly created TuioToken.
         *
         * @param	si	the Session ID to assign
         * @param	sym	the Symbol ID  to assign
         * @param	xp	the X coordinate to assign
         * @param	yp	the Y coordinate to assign
         * @param	a	the angle to assign
         */
        TuioToken (int si, int sym, float xp, float yp, float a);
		
		/**
		 * This constructor takes the atttibutes of the provided TuioToken 
		 * and assigs these values to the newly created TuioToken.
		 *
		 * @param	ttok	the TuioToken to assign
		 */
		TuioToken (TuioToken *ttok);
		
		/**
		 * The destructor is doing nothing in particular. 
		 */
		~TuioToken() {};

		/**
		 * This method is used to calculate the speed and acceleration values of a
		 * TuioToken with unchanged position and angle.
		 */
		void stop (TuioTime ttime);
		
		/**
		 * Takes the atttibutes of the provided TuioToken 
		 * and assigs these values to this TuioToken.
		 * The TuioTime time stamp of this TuioToken remains unchanged.
		 *
		 * @param	ttok	the TuioToken to assign
		 */	
		void update (TuioToken *ttok);
		
		/**
		 * Returns the symbol ID of this TuioToken.
		 * @return	the symbol ID of this TuioToken
		 */
		int getSymbolID() const;
        
        /**
         * Returns the Type ID of this TuioToken.
         * @return	the Type ID of this TuioToken
         */
        short getTypeID() const;
        
        /**
         * Returns the User ID of this TuioToken.
         * @return	the User ID of this TuioToken
         */
        short getUserID() const;
        
        /**
         * Returns the encoded Type & User ID of this TuioToken.
         * @return	the encoded Type & User ID of this TuioToken
         */
        int getTypeUserID() const;
        
        /**
         * Decodes and assigns the Type & User ID to this TuioToken.
         * @param tu_id   the encoded Type & User ID of this TuioToken
         */
        void setTypeUserID(int tu_id);
	};
}
#endif
