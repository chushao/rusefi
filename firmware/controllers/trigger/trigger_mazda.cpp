/**
 * @file	trigger_mazda.cpp
 *
 * @date Feb 18, 2014
 * @author Andrey Belomutskiy, (c) 2012-2016
 *
 * This file is part of rusEfi - see http://rusefi.com
 *
 * rusEfi is free software; you can redistribute it and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * rusEfi is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include "trigger_mazda.h"

void initializeMazdaMiataNaShape(TriggerShape *s DECLARE_ENGINE_PARAMETER_S) {
	s->initialize(FOUR_STROKE_CAM_SENSOR, true);
	s->setTriggerSynchronizationGap2(1.4930 * 0.6f, 1.4930 * 1.3f);
	s->useRiseEdge = false;

	s->tdcPosition = 294;

	s->isSynchronizationNeeded = true;

	/**
	 * http://rusefi.com/forum/viewtopic.php?f=3&t=729&p=12983#p12983
	 */
	s->addEvent(52.960405, T_SECONDARY, TV_RISE);
	s->addEvent(122.635956, T_SECONDARY, TV_FALL);

	s->addEvent(216.897031, T_PRIMARY, TV_RISE);
	s->addEvent(232.640068, T_SECONDARY, TV_RISE);
	s->addEvent(288.819688, T_PRIMARY, TV_FALL);
	s->addEvent(302.646323, T_SECONDARY, TV_FALL);

	s->addEvent(412.448056, T_SECONDARY, TV_RISE);
	s->addEvent(482.816719, T_SECONDARY, TV_FALL);

	s->addEvent(577.035495, T_PRIMARY, TV_RISE);
	s->addEvent(592.878113, T_SECONDARY, TV_RISE);
	s->addEvent(662.899708, T_SECONDARY, TV_FALL);
	s->addEvent(720.0f, T_PRIMARY, TV_FALL);
	s->useOnlyPrimaryForSync = true;
}

void initializeMazdaMiataNbShape(TriggerShape *s DECLARE_ENGINE_PARAMETER_S) {
	s->initialize(FOUR_STROKE_CAM_SENSOR, true);
	s->setTriggerSynchronizationGap(0.11f);
	s->useRiseEdge = false;

	s->invertOnAdd = true;

	/**
	 * cam sensor is primary, crank sensor is secondary
	 */
	s->addEvent(20.0f, T_PRIMARY, TV_RISE);

	s->addEvent(66.0f, T_SECONDARY, TV_FALL);
	s->addEvent(70.0f, T_SECONDARY, TV_RISE);
	s->addEvent(136.0f, T_SECONDARY, TV_FALL);
	s->addEvent(140.0f, T_SECONDARY, TV_RISE);
	s->addEvent(246.0f, T_SECONDARY, TV_FALL);
	s->addEvent(250.0f, T_SECONDARY, TV_RISE);
	s->addEvent(316.0f, T_SECONDARY, TV_FALL);
	s->addEvent(320.0f, T_SECONDARY, TV_RISE);

	s->addEvent(340.0f, T_PRIMARY, TV_FALL);
	s->addEvent(360.0f, T_PRIMARY, TV_RISE);

	s->addEvent(380.0f, T_PRIMARY, TV_FALL);
	s->addEvent(400.0f, T_PRIMARY, TV_RISE);

	s->addEvent(426.0f, T_SECONDARY, TV_FALL);
	s->addEvent(430.0f, T_SECONDARY, TV_RISE);
	s->addEvent(496.0f, T_SECONDARY, TV_FALL);
	s->addEvent(500.0f, T_SECONDARY, TV_RISE);
	s->addEvent(606.0f, T_SECONDARY, TV_FALL);
	s->addEvent(610.0f, T_SECONDARY, TV_RISE);
	s->addEvent(676.0f, T_SECONDARY, TV_FALL);
	s->addEvent(680.0f, T_SECONDARY, TV_RISE);

	s->addEvent(720.0f, T_PRIMARY, TV_FALL);
	s->useOnlyPrimaryForSync = true;
}

void configureMazdaProtegeSOHC(TriggerShape *s DECLARE_ENGINE_PARAMETER_S) {

	// todo: move to into configuration definition s->needSecondTriggerInput = FALSE;

	s->initialize(FOUR_STROKE_CAM_SENSOR, false);
//	s->initialState[0] = 1;

//	float w = 720 / 4 * 0.215;
	float a = 5;

	float z = 0.093;
	a = 180;
	s->addEvent(a - z * 720, T_PRIMARY, TV_RISE);
	s->addEvent(a, T_PRIMARY, TV_FALL);

	a += 180;
	s->addEvent(a - z * 720, T_PRIMARY, TV_RISE);
	s->addEvent(a, T_PRIMARY, TV_FALL);
	a += 180;
	s->addEvent(a - z * 720, T_PRIMARY, TV_RISE);
	s->addEvent(a, T_PRIMARY, TV_FALL);
	a += 180;
	s->addEvent(a - z * 720, T_PRIMARY, TV_RISE);
	s->addEvent(a, T_PRIMARY, TV_FALL);

	s->isSynchronizationNeeded = false;
}

void configureMazdaProtegeLx(TriggerShape *s DECLARE_ENGINE_PARAMETER_S) {
	// todo: move to into configuration definition s->needSecondTriggerInput = FALSE;
	s->initialize(FOUR_STROKE_CAM_SENSOR, true);
	s->useOnlyPrimaryForSync = true;

	/**
	 * based on https://svn.code.sf.net/p/rusefi/code/trunk/misc/logs/1993_escort_gt/MAIN_rfi_report_2015-02-01%2017_39.csv
	 */
	s->addEvent2(95.329254, T_PRIMARY, TV_RISE PASS_ENGINE_PARAMETER);

	s->addEvent2(95.329254 + 14.876692, T_SECONDARY, TV_RISE PASS_ENGINE_PARAMETER);
	s->addEvent2(95.329254 + 82.693557, T_SECONDARY, TV_FALL PASS_ENGINE_PARAMETER);

	s->addEvent2(95.329254 + 137.119154, T_PRIMARY, TV_FALL PASS_ENGINE_PARAMETER);

	s->addEvent2(95.329254 + 192.378308, T_SECONDARY, TV_RISE PASS_ENGINE_PARAMETER);
	s->addEvent2(95.329254 + 261.556418, T_SECONDARY, TV_FALL PASS_ENGINE_PARAMETER);

	s->addEvent2(95.329254 + 373.060597, T_SECONDARY, TV_RISE PASS_ENGINE_PARAMETER);
	s->addEvent2(95.329254 + 443.503184, T_SECONDARY, TV_FALL PASS_ENGINE_PARAMETER);

	s->addEvent2(95.329254 + 555.349776, T_SECONDARY, TV_RISE PASS_ENGINE_PARAMETER);
	s->addEvent2(720, T_SECONDARY, TV_FALL PASS_ENGINE_PARAMETER);

	s->tdcPosition = 137.119154;
	s->isSynchronizationNeeded = false;
}
