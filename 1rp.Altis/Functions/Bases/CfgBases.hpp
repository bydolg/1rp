class CfgBases {
	// Bidding info...
	Day = "Saturday";
	Restart[] = {20, 24};
	RedzoneKillReward = 15000;
	BidIncrement = 1000000;
	StartingBid = 9000000; // StartingBid = BidIncrement + StartingBid

	class North {
		icon = "\dataM\UI\Spawns\base.paa";
		displayName = "Северная База";
		position[] = {{12044.9, 10492.4, -0.303827}, 0};
		includeBidding = true;
		defaultGroupOwnerId = -1;
		class Spawn {
			marker = "gang_base_1";
		};
	};

	class South : North {
		displayName = "Южная База";
		position[] = {{12295.3,8872.94,0.00119019}, 289.015};
		class Spawn {
			marker = "gang_base_2";
		};
	};
};