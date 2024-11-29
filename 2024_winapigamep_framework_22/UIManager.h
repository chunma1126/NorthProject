#pragma once
class UI;
class UIManager
{
	DECLARE_SINGLE(UIManager);

public:
	void Init();
	void Update();
	void Render(HDC _hdc);

public :
	void AddChild(wstring _key,UI* _newUI);


private :
	map<wstring, UI*> uiLists;


};

