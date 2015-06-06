// coding: utf-8
// ----------------------------------------------------------------------------
/* Copyright (c) 2015, Roboterclub Aachen e.V.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Roboterclub Aachen e.V. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ROBOTERCLUB AACHEN E.V. ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBOTERCLUB AACHEN E.V. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
// ----------------------------------------------------------------------------
// created with FontCreator 3.0

#include <xpcc/architecture/driver/accessor.hpp>

namespace xpcc
{
	namespace font
	{
		FLASH_STORAGE(uint8_t Numbers14x32[]) =
		{
			0x42, 0x02, // total size of this array
			14,	// width (may vary)
			32,	// height
			3,	// hspace
			4, 	// vspace
			48,	// first char
			10,	// char count
			
			// char widths
			// for each character the separate width in pixels
			14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 
			
			// font data
			// bit field of all characters
			0xF0, 0xFC, 0xFE, 0xFE, 0x1F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1F, 0xFE, 0xFE, 0xFC, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x80, 0xC0, 0xF0, 0x7C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3E, 0x0F, 0x03, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x3F, 0x7F, 0x7F, 0xF8, 0xF0, 0xF0, 0xF0, 0xF0, 0xF8, 0x7F, 0x7F, 0x3F, 0x0F, // 48
			0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xFC, 0x7E, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x0C, 0x0F, 0x0F, 0x07, 0x03, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0x7F, 0x00, // 49
			0x30, 0x7C, 0x7E, 0x3E, 0x1F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1F, 0xFE, 0xFE, 0xFC, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xFF, 0xFF, 0x7F, 0x1F, 0xC0, 0xF0, 0xF8, 0xFC, 0x7E, 0x3F, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0x60, // 50
			0x30, 0x7C, 0x7E, 0x3E, 0x1F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1F, 0xFE, 0xFE, 0xFC, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xE0, 0xFF, 0xFF, 0x7F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x07, 0xFF, 0xFF, 0xFE, 0xF8, 0x0C, 0x3E, 0x7E, 0x7C, 0xF8, 0xF0, 0xF0, 0xF0, 0xF0, 0xF8, 0x7F, 0x7F, 0x3F, 0x0F, // 51
			0x00, 0x00, 0x00, 0x00, 0x80, 0xF0, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x80, 0xF0, 0xFE, 0xFF, 0x3F, 0x07, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0xE7, 0xE0, 0xE0, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xE0, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x7F, 0xFF, 0xFF, 0x7F, 0x01, 0x01, // 52
			0xFE, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x06, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0xC0, 0x80, 0x01, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x0C, 0x3E, 0x7E, 0x7C, 0xF8, 0xF0, 0xF0, 0xF0, 0xF8, 0xFC, 0x7F, 0x3F, 0x1F, 0x07, // 53
			0xE0, 0xF8, 0xFC, 0xFE, 0x1E, 0x0F, 0x0F, 0x0F, 0x0F, 0x1F, 0x3E, 0x7E, 0x7C, 0x30, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0xC0, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x1F, 0x3F, 0x7F, 0x78, 0xF0, 0xF0, 0xF0, 0xF0, 0x78, 0x7F, 0x3F, 0x1F, 0x07, // 54
			0x06, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0xFE, 0xFF, 0x3F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, // 55
			0xE0, 0xF8, 0xFC, 0xFE, 0x1E, 0x0F, 0x0F, 0x0F, 0x0F, 0x1E, 0xFE, 0xFC, 0xF8, 0xE0, 0x0F, 0x3F, 0x7F, 0xFF, 0xF0, 0xE0, 0xC0, 0xC0, 0xE0, 0xF0, 0xFF, 0x7F, 0x3F, 0x0F, 0xF0, 0xFC, 0xFE, 0xFF, 0x0F, 0x07, 0x03, 0x03, 0x07, 0x0F, 0xFF, 0xFE, 0xFC, 0xF0, 0x07, 0x1F, 0x3F, 0x7F, 0x78, 0xF0, 0xF0, 0xF0, 0xF0, 0x78, 0x7F, 0x3F, 0x1F, 0x07, // 56
			0xE0, 0xF8, 0xFC, 0xFE, 0x1E, 0x0F, 0x0F, 0x0F, 0x0F, 0x1E, 0xFE, 0xFC, 0xF8, 0xE0, 0x3F, 0xFF, 0xFF, 0xFF, 0xE0, 0xC0, 0x80, 0x80, 0xC0, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x0C, 0x3E, 0x7E, 0x7C, 0xF8, 0xF0, 0xF0, 0xF0, 0xF0, 0xF8, 0x7F, 0x7F, 0x3F, 0x0F, // 57
		};
	}
}

