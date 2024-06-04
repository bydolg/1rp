/*
	Area Defending System (ADS) - by Enigx
	
	ADS_HideAreas.sqf
	
	Insert in this instruction EXACTLY the names of the two  markers of the areas introduced in the editor, in a manner similar to what 
	has already been specified in the instruction in ADS_OpenMe.sqf, i.e. this part
		
			null = [...,...,[...,...],  ["MARKER_AREA_EXT","MARKER_AREA_INT"]  ,...,..] execVM "ADS_system\functions\launchADS.sqf";
		
	The instruction below must therefore be completed as
	
	_MKAreas =["MARKER_AREA_EXT","MARKER_AREA_INT"];	
	
	where in quotes put the names given to the areas as in the editor in the same way as done in the file ADS_OpenMe.sqf

	Example 1 as in ADS_OpenMe.sqf
		
		_MKAreas =["A_ext","A_int"];
		
*/


// ** MODIFY BELOW BY ENTERING THE NAMES OF THE TWO MARKER AREAS AS DEFINED IN THE ADS_OpenMe.sqf

_MKAreas =["MkAreaSpawn","MkAreaSafe"];
 
 

// ************** DO NOT MODIFY THIS SECTION ***************************
for "_i" from 0 to 1 do {
(_MKAreas select _i) setMarkerAlpha 0;
};
// *********************************************************************