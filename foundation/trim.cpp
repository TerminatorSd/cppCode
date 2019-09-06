string trim(string s) {
	string res;
	for(int i = 0, len = s.size(); i < len; i++) {
		if(s[i] != ' ') {
			res += s[i];
		}
	}
	return res;
}
