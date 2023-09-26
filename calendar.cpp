#include "calendar.h"
#include "sequence.h"
#include "application.h"

CCalender::CCalender()
{
	for (int i = 0; i < 49; i++)
	{
		m_day[i] = nullptr;
	}
}

CCalender::~CCalender()
{
}

HRESULT CCalender::Init()
{
	CObject2D::Init();

	SetSize(D3DXVECTOR2(0.0f,0.0f));
	SetPos(D3DXVECTOR3(CApplication::CENTER_X + CApplication::CENTER_X * 0.5f, CApplication::CENTER_Y, 0.0f));

	SYSTEMTIME time;
	GetLocalTime(&time);
	int day = time.wDay;

	int week = ((day % 7) - 1) * -1 + time.wDayOfWeek;

	if (week < 0)
	{
		week = 7 - week;
	}

	if (week == 7)
	{
		week = 0;
	}

	int month = time.wMonth;
	int year = time.wYear;
	int monthDay;

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		monthDay = 30;
	}
	else if (month == 2)
	{
		bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (isLeapYear)
		{
			monthDay = 29;
		}
		else
		{
			monthDay = 28;
		}
	}
	else
	{
		monthDay = 31;
	}

	int cnt = 0;
	float size = 70.0f;
	float spase = 40.0f;
	for (int i = week; i < 49;i++)
	{
		if (cnt == monthDay)
		{
			break;
		}

		cnt++;
		D3DXVECTOR3 pos(CApplication::CENTER_X, CApplication::CENTER_Y, 0.0f);
		pos.x += -((size + spase) * 3.5f) + (size + spase) * (i % 7) + spase * 0.5f;
		pos.y += -((size + spase) * 3.5f) + (size + spase) * (i / 7) + spase * 0.5f;

		m_tag[i] = CObject2D::Create();
		m_tag[i]->SetPos(pos);
		m_tag[i]->SetSize(D3DXVECTOR2(size, size) * 1.2f);
		m_tag[i]->SetTexture("DECO_TAG");

		m_day[i] = CSequence::Create(pos,D3DXVECTOR2(size / 3.0f - 0.9f, size),2);
		m_day[i]->SetNumber(cnt);
	}

	return S_OK;
}

void CCalender::Update()
{
}

CCalender * CCalender::Create()
{
	CCalender* calender = new CCalender;

	assert(calender != nullptr);

	calender->Init();
	return calender;
}
