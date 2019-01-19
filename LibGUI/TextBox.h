#pragma once

#include "Widget.h"
#include <AK/Function.h>

class TextBox final : public Widget {
public:
    explicit TextBox(Widget* parent = nullptr);
    virtual ~TextBox() override;

    String text() const { return m_text; }
    void setText(String&&);

    Function<void(TextBox&)> onReturnPressed;

private:
    virtual const char* class_name() const override { return "TextBox"; }
    virtual void paintEvent(PaintEvent&) override;
    virtual void mouseDownEvent(MouseEvent&) override;
    virtual void keyDownEvent(KeyEvent&) override;
    virtual void timerEvent(TimerEvent&) override;

    void handleBackspace();

    String m_text;
    unsigned m_cursorPosition { 0 };
    bool m_cursorBlinkState { false };
};
