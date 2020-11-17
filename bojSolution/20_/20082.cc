#include "laugh.h"

int longest_laugh(std::string s)
{
	int ret = 0, streak = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'a') {
			if (i == 0 || s[i - 1] != 'h') {
				streak = 1;
			}
			else {
				streak += 1;
			}
		}
		if (s[i] == 'h') {
			if (i == 0 || s[i - 1] != 'a') {
				streak = 1;
			}
			else {
				streak += 1;
			}
		}
		ret = (ret > streak ? ret : streak);
	}
	return ret;
}