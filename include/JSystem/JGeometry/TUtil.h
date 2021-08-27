#pragma once

namespace JGeometry
{
	template<typename T>
	class TUtil
	{
	public:
		static T PI();

		static T asin(T);
		static T acos(T);

		static T sqrt(T);
		static T inv_sqrt(T);

		static T clamp(T, T, T);
		
		static bool epsilonEquals(T, T, T);
	};
};
