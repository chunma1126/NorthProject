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
	void SetActiveChild(wstring _key , bool _active);
	UI* GetChild(wstring _key);


private :
	std::map<wstring, UI*> uiLists;

};

