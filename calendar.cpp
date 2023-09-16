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
	float size = 40.0f;
	for (int i = week; i < 49;i++)
	{
		if (cnt == monthDay)
		{
			break;
		}

		cnt++;
		D3DXVECTOR3 pos(CApplication::CENTER_X, CApplication::CENTER_Y,0.0f);
		pos.x += -(size * 7.0f) + size * 2.0f * (i % 7);
		pos.y += -(size * 7.0f) + size * 2.0f * (i / 7);
		m_day[i] = CSequence::Create(pos,D3DXVECTOR2(size / 3.0f - 0.9f, size));
		m_day[i]->SetNumber(cnt);
	}

	return S_OK;
}

void CCalender::Update()
{
}

CCalender * CCalender::Create()
{
	return nullptr;
}
