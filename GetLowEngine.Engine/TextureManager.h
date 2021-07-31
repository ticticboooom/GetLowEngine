#pragma once
class TextureManager
{
public:
	TextureManager();
	static std::shared_ptr<TextureManager> GetInstance();
	int CreateSRVFromTextureFile(std::wstring texturePath);
private:
	static std::shared_ptr<TextureManager> instance;
	int m_SRVSlot;
};

